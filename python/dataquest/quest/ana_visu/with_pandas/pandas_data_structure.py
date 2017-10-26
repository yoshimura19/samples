#coding:utf-8

import pandas as pd
#from pandas import Series

fandango = pd.read_csv("fandango_score_comparison.csv")
cols = list(fandango.columns)
#print(fandango.head(2))
#print(cols)

series_film = fandango["FILM"]
#print(series_film.head(5))

series_rt = fandango["RottenTomatoes"]
#print(series_rt.head(5))


#Series関数
film_names = series_film.values
rt_scores = series_rt.values
series_custom = pd.Series(rt_scores, index=film_names)

#このSeries objectはlistとdictionary形式どちらとしても使える
print("\nlist形式:\n{0}".format(series_custom[['Minions (2015)', 'Leviathan (2014)']]))
print("\ndictionary形式:\n{0}".format(series_custom[5:10]))


#Reindexing
original_index = series_custom.index.tolist()
#print(original_index)
sorted_index = sorted(original_index)
sorted_by_index = series_custom.reindex(sorted_index)
#print(sorted_index)
print("\nsorted_by_index:\n{0}".format(sorted_by_index[0:10]))


#pandasはsort_index(), sort_values()メソッドを持つ
sc2 = series_custom.sort_index()
sc3 = series_custom.sort_values()
print("\nindexでソート:\n{0}".format(sc2[0:10]))
print("\nvalueでソート:\n{0}".format(sc3[0:10]))


series_normalized = (series_custom / 20)
print(series_normalized.head(5))

#行列から取り出すためのboolean
criteria_one = series_custom > 50
criteria_two = series_custom < 75

#2つのbooleanの列の条件を満たす列
both_criteria = series_custom[criteria_one & criteria_two]
print("\nsatisfies criteria of 50 < series_custom < 75:\n{0}".format(both_criteria))


rt_critics = pd.Series(fandango['RottenTomatos'].values, index= fandango['FILM'])
rt_users = pd.Series(fandango['RottenTomatos_User'].values, index= fandango['FILM'])

rt_mean = (rt_critics + rt_users) / 2
print(rt_mean)


