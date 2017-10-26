#coding:utf-8

import csv

# f = open("world_alcohol.csv", "r")
# world_alcohol = list(csv.reader(f))

# years = []
# for a_list in world_alcohol:
#     years.append(a_list[0])

# years = years[1:]
# total = 0
# for year in years:
#     total += float(year)
# avg_year = total / len(years)
# print(avg_year)


###### Using Numpy ######
import numpy as np

world_alcohol = np.genfromtxt("world_alcohol.csv", delimiter = ",")
vector = np.array([10, 20, 30])
matrix = np.array([[5, 10, 15], [20, 25, 30], [35, 40, 45]])
print(matrix)
vector_shape = vector.shape; matrix_shape = matrix.shape
print(vector_shape, matrix_shape)

##### world_alcohol with Numpy ######
world_alcohol = np.array(world_alcohol)
#print(world_alcohol)
print(world_alcohol.dtype)    #data type


###### Reading properly #######
world_alcohol = np.genfromtxt("world_alcohol.csv", delimiter = ",", dtype = "U75", skip_header = True)
#print(world_alcohol)

world_alcohol = np.array(world_alcohol)
uruguay_other_1986 = world_alcohol[1,4]
third_country = world_alcohol[2,2]
print("world_alcohol[1,4]:{0}, world_alcohol[2,2]:{1}".format(uruguay_other_1986, third_country))


##### slicing matrix ######
countries = world_alcohol[:,2]
alcohol_consumption = world_alcohol[:,4]
#print(countries)
first_two_columns = world_alcohol[:,:2]
first_ten_years = world_alcohol[:10,0]
first_ten_rows = world_alcohol[:10,:]
print(first_two_columns)
