#coding:utf-8
#boolean.py

crime_rates = [749, 371, 828, 503, 1379, 425, 408, 542, 1405, 835, 1288, 647, 974, 1383, 455, 658, 675, 615, 2122, 423, 362, 587, 543, 563, 168, 992, 1185, 617, 734, 1263, 784, 352, 397, 575, 481, 598, 1750, 399, 1172, 1294, 992, 522, 1216, 815, 639, 1154, 1993, 919, 594, 1160, 636, 752, 130, 517, 423, 443, 738, 503, 413, 704, 363, 401, 597, 1776, 722, 1548, 616, 1171, 724, 990, 169, 1177, 742]

second_500 = (crime_rates[1] < 500)
second_371 = (crime_rates[1] <= 371)
second_last = (crime_rates[1] <= crime_rates[-1])

print(second_500, second_371, second_last)
#print('\n')


results = 0
if crime_rates > 500:
    if crime_rates > 300:
        results = 3

print(results)
#print('\n')



five_hundred_list = []
for rate in crime_rates:
    if rate > 500:
        five_hundred_list.append(rate)

#print(five_hundred_list)
#print('\n')


i = 0
highest = 0
for rate in crime_rates:
    if rate > highest:
        highest = rate

print(highest)
