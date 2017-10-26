#coding:utf-8

import csv
f = open("nfl_suspensions_data.csv", "r")
nfl_suspensions = list(csv.reader(f))
f.close()
#header:name(0),team(1),games(2),category(3),desc.(4),year(5),source(6)


nfl_suspensions = nfl_suspensions[1:]  #remove the header

years = {}
for row in nfl_suspensions:
    row_year = row[5]
    if row_year in years:
        years[row_year] += 1
    else:
        years[row_year] = 1
#print(years)

unique_teams = set([row[1] for row in nfl_suspensions])
unique_games = set([row[2] for row in nfl_suspensions])
print("unique_teams:\n{0}\nunique_games:\n{1}".format(unique_teams,unique_games))


class Suspension():   #classは大文字から
    def __init__(self,row):
        self.name = row[0]
        self.team = row[1]
        self.games = row[2]
        try:
            self.year = int(row[5])
        except Exception:
            self.year = 0

    def get_year(self):
        return self.year

missing_year = Suspension(nfl_suspensions[22])
twenty_third_year = missing_year.get_year()
print(twenty_third_year)

third_suspension = Suspension(nfl_suspensions[2])
print(third_suspension.name)
