#coding:utf-8
#missingデータの扱い、dataframeにapplyでfunction使用
#pivotテーブル

import pandas as pd
import numpy as np

f = "titanic_survival.csv"
titanic_survival = pd.read_csv(f)

age_null = pd.isnull(titanic_survival["age"])
# age_null is a boolean vector

# age_null_count = 0
# for element in age_null:
#     if element == True:
#         age_null_count += 1
# print(age_null_count)

age_null_true = age_null[age_null == True]
age_null_count = len(age_null_true)
#print(age_null_true)

good_ages = titanic_survival["age"][age_null == False]
correct_mean_age = sum(good_ages) / len(good_ages)
#print(correct_mean_age)


#pandas dataform method
correct_mean_age = titanic_survival["age"].mean()
correct_mean_fare = titanic_survival["fare"].mean()


passenger_classes = [1, 2, 3]
fares_by_class = {}
for pas_class in passenger_classes:
    fares_by_class[pas_class] = titanic_survival["fare"][titanic_survival["pclass"] == pas_class].mean()
print(fares_by_class)

passanger_survival = titanic_survival.pivot_table(index="pclass", values="survived", aggfunc=np.mean)
passenger_age = titanic_survival.pivot_table(index="pclass", values="age", aggfunc=np.mean)
print(passenger_age)


port_stats = titanic_survival.pivot_table(index="embarked", values=["age", "survived", "fare"], aggfunc = np.mean)
print(port_stats)


#drop missing values
new_titanic_survival = titanic_survival.dropna(subset=["age", "body", "home.dest"])


row_index_25 = new_titanic_survival.loc[25,:]    #locは名前指定可？
row_position_fifth = new_titanic_survival.iloc[4,:]   #ilocは順序(番号)のリスト
print(row_index_25)
print(row_position_fifth)
row_25_survived = new_titanic_survival.loc[25, "survived"]


new_titanic_survival = titanic_survival.dropna(subset=["age", "boat"])
titanic_reindexed = new_titanic_survival.reset_index(drop=True)


def null_count(column):
    column_null = pd.isnull(column)
    null = column[column_null == True]
    return len(null)
column_null_count = titanic_survival.apply(null_count)
print(column_null_count)          #applyはfunctionをeach columnに適用


def age_class(row):
    if row["age"] < 18:
        return "minor"
    elif row["age"] >= 18:
        return "adult"
    else:
        return "unknown"

age_labels = titanic_survival.apply(age_class, axis=1)
print(age_labels)


age_group_survival = titanic_survival.pivot_table(index="age_labels", values="survived", aggfunc = np.mean)
print(age_group_survival)
