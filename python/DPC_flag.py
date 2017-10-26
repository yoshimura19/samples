#coding:utf-8

#編集元ファイルは"DPCに係る調査_厚生労働省"の"施設概要表",headerの変数名を以下に変更
#informed_id,tsu-ban,name,when_attend,beds,type,rate_of_DPCbeds,mental_beds,ryoyo_beds,kekkaku_beds,total_beds,teisyutsu_month


import pandas as pd
import numpy as np
import re           #regular expression

shisetsu_gaiyo = pd.read_csv("shisetsu.csv")
#print(shisetsu_gaiyo.head())
print(shisetsu_gaiyo.columns)     #変数リスト
#print(shisetsu_gaiyo["when_attend"])

the_year_attend = shisetsu_gaiyo["when_attend"]
#print(the_year_attend)

pat = re.compile("平成(.*)年度DPC参加病院")
pat2 = re.compile("平成([0-9]+)年度新規DPC準備病院")


#ダミーの2次元配列
DPCdummy = np.zeros((12, 1849))   #H15-H26(12年分)1849がサンプルサイズ
pre_DPCdummy = np.zeros((9,1849))  #H18-H26(9年分)

count = 0
for attend in the_year_attend:     #??年度新規加入or新規準備
    if pat.match(attend) != None:    #新規加入病院のケース
        count += 1
        temp = pat.search(attend)
        attend_year = int(temp.group(1))  #年度加入したか(15~26)

        for i in range(12):            #加入した年の列に1を立てる
            if attend_year == 15 + i:
                DPCdummy[i][count - 1] = 1

    elif pat2.match(attend) != None:    #準備病院のケース
        count += 1
        temp = pat2.search(attend)
        attend_year = int(temp.group(1))

        for i in range(9):
            if attend_year == 18 + i:  #H18から
                pre_DPCdummy[i][count - 1] = 1
    else:                              #出来高算定病院
        break

#ダミー変数データフレーム
df_DPC_dummy = pd.DataFrame(DPCdummy.T, columns = ['H15d','H16d','H17d','H18d','H19d','H20d','H21d','H22d','H23d','H24d','H25d','H26d'])
df_pre_DPC_dummy = pd.DataFrame(pre_DPCdummy.T, columns = ['H18d_pre','H19d_pre','H20d_pre','H21d_pre','H22d_pre','H23d_pre','H24d_pre','H25d_pre','H26d_pre'])
#print(df_DPC_dummy)
#print(df_pre_DPC_dummy)



################ その時点加入(累積)のダミーを作る ####################
cum_DPCdummy = np.zeros((12, 1849))   #H15-H26(12年分)
cum_pre_DPCdummy = np.zeros((9,1849))  #H18-H26(9年分)

cum_DPCdummy[:] = DPCdummy  #参照渡しにならないように。
for i in range(1,12):    #その加入時点からDPC病院の1をたてる
    cum_DPCdummy[i] = cum_DPCdummy[i] + cum_DPCdummy[i-1]  #H15はそのまま

cum_pre_DPCdummy[:] = pre_DPCdummy
for i in range(1,9):
    cum_pre_DPCdummy[i] = cum_pre_DPCdummy[i] + cum_pre_DPCdummy[i-1]  #H18はそのまま

#累積ダミー変数データフレーム
df_cum_DPC_dummy = pd.DataFrame(cum_DPCdummy.T, columns = ['H15_DPC','H16_DPC','H17_DPC','H18_DPC','H19_DPC','H20_DPC','H21_DPC','H22_DPC','H23_DPC','H24_DPC','H25_DPC','H26_DPC'])
df_cum_pre_DPC_dummy = pd.DataFrame(cum_pre_DPCdummy.T, columns = ['H18_DPC_pre','H19_DPC_pre','H20_DPC_pre','H21_DPC_pre','H22_DPC_pre','H23_DPC_pre','H24_DPC_pre','H25_DPC_pre','H26_DPC_pre'])


#型変換
df_DPC_dummy = df_DPC_dummy.astype(int); df_pre_DPC_dummy = df_pre_DPC_dummy.astype(int)
df_cum_DPC_dummy = df_cum_DPC_dummy.astype(int); df_cum_pre_DPC_dummy = df_cum_pre_DPC_dummy.astype(int)


#確認用出力
print("DPC新規導入数:\n{0}".format(df_DPC_dummy.sum()))
print("新規DPC準備病院数:\n{0}".format(df_pre_DPC_dummy.sum()))

print("DPC導入病院数:\n{0}".format(df_cum_DPC_dummy.sum()))
print("現在DPC準備病院数:\n{0}".format(df_cum_pre_DPC_dummy.sum()))


#出力用データフレーム作成
Dummys = pd.concat([df_cum_DPC_dummy, df_cum_pre_DPC_dummy, df_DPC_dummy, df_pre_DPC_dummy], axis=1)

pd.concat([shisetsu_gaiyo, Dummys], axis=1).to_csv("DPC導入病院一覧.csv")
#Dummys.to_csv("DPC_dummy.csv")



#intへ、list(map(int, x))

