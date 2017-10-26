#coding:utf-8

import csv

f = open("lagislators.csv", "r")
legislators = list(csv.reader(f)) #list of lists
f.close()
#ヘッダーはlast_name,first_name,birthday,gender,type,state,party
#print(legislators)

gender = []
party = []
birth_years = []
for row in legislators:
    parts = row[2].split("-")
    birth_years.append(parts[0])
    if row[3] == "":
        row[3] = "M"
    if row[6] == "":
        row[6] = "No Party"
    gender.append(row[3])
    party.append(row[6])

#print(gender)
print(set(gender))
print(set(party))
print(birth_years)


#Exception Instances
try:
    int("")
except Exception as exc:
    print(type(exc))
    print(str(exc))
#<class 'ValueError'>
#invalid literal for int() with base 10: ''
