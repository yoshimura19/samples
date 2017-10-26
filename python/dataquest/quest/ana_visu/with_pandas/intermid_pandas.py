#coding:utf-8
#dataframeを使った計算

import pandas as pd

food_info = pd.read_csv("food_info.csv")
cols = list(food_info.columns)
#cols = food_info.columns.tolist()

#print(cols)
#print(food_info.head(3))

sodium_grams = food_info["Sodium_(mg)"] / 1000
sugar_milligrams = food_info["Sugar_Tot_(g)"] * 1000


grams_of_protein_per_gram_of_water = food_info["Protein_(g)"] / food_info["Water_(g)"]
milligrams_of_calcium_and_iron = food_info["Calcium_(mg)"] + food_info["Iron_(mg)"]


#formula: Score = 2 * (Protein_(g)) - 0.75 * (Lipid_Tot_(g))
weighted_protein = food_info["Protein_(g)"] * 2
weighted_fat = (-0.75) * food_info["Lipid_Tot_(g)"]
initial_rating = weighted_protein + weighted_fat


normalized_protein = food_info["Protein_(g)"] / food_info["Protein_(g)"].max()
normalized_fat = food_info["Lipid_Tot_(g)"] / food_info["Lipid_Tot_(g)"].max()


#creating a new column for dataframe
food_info["Normalized_Protein"] = normalized_protein
food_info["Normalized_Fat"] = normalized_fat
food_info["Norm_Nutr_Index"] = 2 * (food_info["Normalized_Protein"]) - 0.75 * (food_info["Normalized_Fat"])


#Sorting A Dataframe By A Column
food_info.sort_values("Norm_Nutr_Index", inplace = True, ascending = False)
