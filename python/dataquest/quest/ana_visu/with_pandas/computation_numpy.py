#coding:utf-8

import numpy as np

dataset = np.genfromtxt("world_alcohol.csv", delimiter = ",", dtype = "U75", skip_header = True)
world_alcohol = np.array(dataset)

countries_canada = (world_alcohol[:,2] == "Canada")
years_1984 = (world_alcohol[:,0] == "1984")
#print(countries_canada)


##### Selecting Elements #####

country_is_algeria = (world_alcohol[:,2] == "Algeria")
country_algeria = world_alcohol[country_is_algeria, :]
print(country_algeria)


##### Multiple Conditions #####
is_algeria_and_1986 = (world_alcohol[:,0] == "1986") & (world_alcohol[:,2] == "Algeria")
# &でand、|でor
rows_with_algeria_and_1986 = world_alcohol[is_algeria_and_1986, :]
print(rows_with_algeria_and_1986)


##### Replacing Values #####
is_1986 = (world_alcohol[:,0] == "1986")
world_alcohol[is_1986, 0] = "2014"
is_Wine = (world_alcohol[:,3] == "Wine")
world_alcohol[is_Wine, 3] = "Grog"


##### Replacing Empty String #####
is_value_empty = (world_alcohol[:,4] == '')
world_alcohol[is_value_empty, 4] = 0


##### Converting Data Type #####
alcohol_consumption = world_alcohol[:,4]
alcohol_consumption = alcohol_consumption.astype(float)
#print(alcohol_consumption)


##### sum(), mean(), max() #####
total_alcohol = alcohol_consumption.sum()
average_alcohol = alcohol_consumption.mean()
print(total_alcohol, average_alcohol)
#matrixの場合、sum(axis=1)で指定、1はrowで0がcolumn


is_canada_1986 = (world_alcohol[:,0] == "1986") & (world_alcohol[:,2] == "Canada")
canada_1986 = world_alcohol[is_canada_1986, :]
is_empty = (canada_1986[:,4] == '')
canada_1986[is_empty, 4] = 0
canada_alcohol = canada_1986[:, 4].astype(float)
total_canadian_drinking = canada_alcohol.sum()
print(total_canadian_drinking)


## Calculating Consumption For Each Country
countries = list(set(world_alcohol[:,2]))

def total_somecountry_drinking(country_name, year, data):
    is_country_year = (data[:,2] == country_name) & (data[:,0] == year)
    country_year = data[is_country_year, :]
    is_empty = (country_year[:,4] == '')
    country_year[is_empty, 4] = 0
    country_alcohol = country_year[:, 4].astype(float)
    total_country_drinking = country_alcohol.sum()
    return total_country_drinking

totals = {}
for name_of_country in countries:
    value = total_somecountry_drinking(name_of_country, "1989", world_alcohol)
    totals[name_of_country] = value
#print(totals)


highest_value = 0
highest_key = None
for key in totals:
    if highest_value < totals[key] or highest_key == None:
        highest_value = totals[key]
        highest_key = key
print("highest_key:{0}, highest_value:{1}".format(highest_key, highest_value))
