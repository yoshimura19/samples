
#coding:utf-8

f = open("crime_rates.csv", "r")

data = f.read()
rows = data.split('\n')
print(rows[0:5])

# final_list = []
# for row in rows:
#     split_list = row.split(',')
#     final_list.append(split_list)

#print(final_list)


int_crime_rates = []
for row in rows:
    sprit_list = row.split(',')
    print(sprit_list)
    rates = int(sprit_list[1])
    int_crime_rates.append(rates)
