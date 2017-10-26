#coding:utf-8

rows = []
genes_info = []

try:
    while True:
        s = raw_input()
        if s == "END": break   #実験用
        rows = s.split("\t")   #!tabじゃなくて空白で分けてしまっている...
        genes_info.append(rows)
except:
    pass
#print(genes_info)

output_dic = {}

output = []   #出力形式 ['染色体名','遺伝子の数','遺伝子の長さ']
count = 0     #遺伝子の数
sum = 0       #遺伝子の長さのsum
name = genes_info[0][0]  #染色体名初期値
for i in range(0, len(genes_info)):
    if name == genes_info[i][0]:
        count += 1
        sum += int(genes_info[i][4]) - int(genes_info[i][3])
    if name != genes_info[i][0]:     #次の名前なので、それまでを集計 
        average = sum / count        #切り捨て平均
        output.append([str(name), str(count), str(average)])
        output_dic = {"name":name, "sum":count, "length":average}
        name = genes_info[i][0]  #更新&カウントリセット    
        count = 0
average = sum / count    #最後の染色体の集計
output.append([str(name), str(count), str(average)]) 
output_dic = {name:(count,average)}

#print(output_dic)
#print(output)
#for i in range(0, len(output)):
#    print("\t".join(output[i]))

for k in sorted(output_dic.keys()):
    s = "%s, %s" % (k, output_dic[k]) 
    s = s.replace(",","\t")
    s = s.replace("(","")
    s = s.replace(")","")
    print s

