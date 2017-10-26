#coding:utf-8

import pandas as pd
fandango = pd.read_csv("fandango_score_comparison.csv")
#print(fandango.head(2))
#print("\nindex:\n{0}".format(fandango.index))


#dataframeは[?:?]形式でdataframeの部分集合
#iloc[]メソッドでindividual rowを選択できるSeries object

#last_num = len(fandango(["FILM"]))   #dataframeはlen()は使えない
last_num = fandango.shape[0] - 1
first_last = fandango.iloc[[0, last_num]]
print(first_last)


#set_index
fandango_films = fandango.set_index("FILM", drop=False)
print(fandango_films.head(2))


#selction row using custom index
best_movies_ever = fandango_films.loc[["The Lazarus Effect (2015)", "Gett: The Trial of Viviane Amsalem (2015)", "Mr. Holmes (2015)"]]
print("\nbest_movies_ever:\n{0}".format(best_movies_ever))
