#coding:utf-8

weather_data = []
f = open("la_weather.csv", "r")
data = f.read()

rows = data.split("\n")
for row in rows:
    split_row = row.split(",")
    weather_data.append(split_row)

#print(weather_data)

weather = []
for item in weather_data:
    type_of_weather = item[1]
    weather.append(type_of_weather)

#print(weather)

count = 0
count = len(weather)

#what is expected on the assignment
count = 0
for item in weather:
    count += 1


