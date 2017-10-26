#coding:utf-8
#指定されたカラムの値が同じものを出力

column_num = int(raw_input())
accord_record = raw_input()   #検索値

row_data = []
family_data = []

try:
    while True:
        s = raw_input()
        row_data = s.split(",")
        family_data.append(row_data)
except EOFError, e:
    pass

output = []
output.append(family_data[0])
for i in range(1,len(family_data)):
    #print(family_data[i][column_num - 1])
    if str(family_data[i][column_num - 1]) == accord_record:
        output.append(family_data[i])

for i in range(0, len(output)):
    print "%s,%s,%s" % (output[i][0],output[i][1],output[i][2])
