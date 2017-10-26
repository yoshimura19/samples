#coding:utf-8

import csv

f = open("lagislators.csv", "r")
legislators = list(csv.reader(f))
f.close()
#ヘッダーはlast_name,first_name,birthday,gender,type,state,party

gender = []
party = []
last_year = 1
for row in legislators:
    parts = row[2].split("-")
    try:
        birth_year = int(parts[0])
        last_year = birth_year
    except Exception:
        birth_year = last_year
    row.append(birth_year)  #added the value in row[7]
    if row[3] == "":
            row[3] = "M"
    if row[6] == "":
        row[6] = "No Party"
    gender.append(row[3])
    party.append(row[6])
#print(legislators)


name_counts = {}
for row in legislators:
    if row[3] == "F" and row[7] > 1940:  #(gender, birth_year)
        name = row[1]     #first_name
        if name in name_counts:
            name_counts[name] += 1
        else:
            nameg_counts[name] = 1

print(name_counts)   #dataがimcompleteのため該当者なし(codeはcorrectだった)


#Comparing with None
values = [-50, -80, -100]
max_value = None
for i in values:
    if max_value is None or i > max_value:
        max_value = i
print(max_value)


values = [None, 10, 20, 30, None, 50]
#checks = []
# for value in values:
#     result =  value is not None and value > 30
#     checks.append(result)
# print(checks)
checks = [x is not None and x > 30 for x in values]
print(checks)


#Highest Female Name Count
max_value = None
for key in name_counts:
    count = name_counts[key]
    if max_value is None or count > max_value:
        max_value = count
print(max_value)

top_female_names = []
for k, v in name_counts:
    if v == 2:
        top_female_names.append(k)
print(top_female_names)  #dataがimcompleteのため該当者なし

highest_male_count = None
for k,v in male_name_counts.items():
    if highest_male_count is None or v > highest_male_count:
        highest_male_count = v
print(highest_male_count)

for k,v in male_name_counts.items():
    if v == highest_male_count:
        top_male_names.append(k)
print(top_male_names)
