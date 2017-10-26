#coding:utf-8

f = open('dq_unisex_names.csv', 'r')

data = f.read()
#print(data)

data_list = data.split("\n")
#print(data_list[0:5])

comma_list = []
string_data = []
for data in data_list:
    comma_list = data.split(",")
    string_data.append(comma_list)
#print(string_data[0:5])


st = ""
fl = 0.0
numerical_data = []
for element in string_data:
    st = element[0]
    fl = float(element[1])
    numerical_data.append([st, fl])
#print(numerical_data)


thousand_or_greater = []
for element in numerical_data:
    if element[1] >= 1000:
        thousand_or_greater.append(element)
print(thousand_or_greater)
