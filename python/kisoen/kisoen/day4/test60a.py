#coding:utf-8
#指定列の入れ替え


column_num = int(raw_input())
exchange_num = int(raw_input())

row_data = []
family_data = []

try:
    while True:
        s = raw_input()
        row_data = s.split(",")
        family_data.append(row_data)
except EOFError, e:
    pass

#print(family_data)

output = []
for i in range(0, len(family_data)):
    temp = family_data[i][column_num - 1]
    family_data[i][column_num - 1] = family_data[i][exchange_num - 1]
    family_data[i][exchange_num - 1] = temp
    output.append(family_data[i])


#print(output)
for i in range(0, len(output)):
    print "%s,%s,%s" % (output[i][0],output[i][1],output[i][2])
