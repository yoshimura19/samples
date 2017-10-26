#coding:utf-8

#必要なダミー変数だけ取り出す用プログラム
#DPC導入病院一覧.csv

import pandas as pd
import numpy as np

dummy_list = pd.read_csv("DPC導入病院一覧.txt")
#informed_id,tsu-ban,name,when_attend,beds,type,rate_of_DPCbeds,mental_beds,ryoyo_beds,kekkaku_beds,total_beds,teisyutsu_month

#H15_DPC,...,H26_DPC    そのとき新規DPC加入
#H18_DPC_pre,...,H26_DPC_pre    そのとき新規準備病院
#H15d,...,H26d          その時点でDPC(累積している)
#H18d_pre,...,H26d_pre     その時点で準備病院


#方法1 df.drop("col_name", axis=1) 消したいheader名を入力
#方法2 df['', '']で取り出す

#必要なダミー変数取り出し
df_want_H26DPC = dummy_list[["informed_id","name","when_attend","H26d","H26_DPC","H25_DPC"]]
df_want_H26DPC.to_csv("H26DPC_list.csv")


#H26新規参入だけ(ブール代数使って)
df_want_onlyH26DPC = df_want_H26DPC[df_want_H26DPC.H26d == 1]
df_want_onlyH26DPC.to_csv("onlyH26DPC_list.csv")
