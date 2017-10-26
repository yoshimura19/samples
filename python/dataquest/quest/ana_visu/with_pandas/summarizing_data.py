#coding:utf-8

import pandas as pd
import numpy as np

all_ages = pd.read_csv("all-ages.csv")
recent_grads = pd.read_csv("recent-grads.csv")

all_ages_major_categories = dict()
recent_grads_major_categories = dict()


print(all_ages.columns)

def calculate_major_category_totals(df):   #df:dataframe
    cats = df['Major_category'].value_counts().index
    counts_dictionary = dict()

    for c in cats:
        major_df = df[df["Major_category"] == c]
        total = major_df["Total"].sum(axis=0)
        counts_dictionary[c] = total
    return counts_dictionary

all_ages_major_categories = calculate_major_category_totals(all_ages)
recent_grads_major_categories = calculate_major_category_totals(recent_grads)
print(all_ages_major_categories)

low_wage_percent = 0.0
low_wage_percent = recent_grads["Low_wage_jobs"].sum(axis=0) / recent_grads["Total"].sum(axis=0)
print(low_wage_percent)


# All majors, common to both DataFrames
majors = recent_grads['Major'].value_counts().index

recent_grads_lower_unemp_count = 0
all_ages_lower_unemp_count = 0

for m in majors:
    recent_grads_row =  recent_grads[recent_grads['Major'] == m]
    all_ages_row = all_ages[all_ages['Major'] == m]

    recent_grads_unemp_rate = recent_grads_row['Unemployment_rate'].values[0]
    all_ages_unemp_rate = all_ages_row['Unemployment_rate'].values[0]

#    all_ages_unemp_rate = all_ages_row['Unemployment_rate']  #これはseries?オブジェクト
#    print("all_ages_unemp_rate:{0}".format(all_ages_unemp_rate))
#    print(type(all_ages_unemp_rate))

    if recent_grads_unemp_rate < all_ages_unemp_rate:
        recent_grads_lower_unemp_count += 1
    elif all_ages_unemp_rate < recent_grads_unemp_rate:
        all_ages_lower_unemp_count += 1
print(recent_grads_lower_unemp_count)
