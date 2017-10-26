#coding:utf-8

import pandas as pd

food_info = pd.read_csv("food_info.csv")
#print(food_info)
#print(type(food_info))

first_rows = food_info.head()
#print(food_info.head(7))
column_names = food_info.columns
#print(column_names)


#hundredth_row = food_info.loc[99] #location
#print(hunredth_row)
#print(food_info.dtypes)

num_rows = food_info.shape[0]
last_rows2 = food_info.loc[num_rows - 5: num_rows]
print(num_rows)
#print(last_rows2)

col_name = "FA_Sat_(g)"
saturated_fat = food_info[col_name]
col_name = "Cholestrl_(mg)"
cholesterol = food_info[col_name]

selenium_thiamin = food_info[["Selenium_(mcg)", "Thiamin_(mg)"]]


column_names = list(food_info.columns)
gram_columns = []
for name in column_names:
    if name.endswith("(g)") == True:
        gram_columns.append(name)

gram_df = food_info[gram_columns]
print(gram_df.head(3))
