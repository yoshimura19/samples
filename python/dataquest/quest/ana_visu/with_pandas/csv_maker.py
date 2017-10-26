#coding:utf-8

import csv
#import world_alcohol as dataset
#import food_info as dataset
import titanic as dataset

#world_alcohol = dataset.data
#food_info = dataset.data
titanic = dataset.data

converting_list = titanic
output_filename = "titanic_survival.csv"


f = open(output_filename, "w")
writer = csv.writer(f)

for a_list in converting_list:
    writer.writerow(a_list)

f.close()
