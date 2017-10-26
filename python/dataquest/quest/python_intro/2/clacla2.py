#coding:utf-8

import csv
class Team():
    def __init__(self, name):
        self.name = name
        f = open("nfl.csv", "r")
        self.nfl = list(csv.reader(f))
        f.close()

    def count_total_wins(self):
        count = 0
        for row in self.nfl:
            if row[2] == self.name:
                count += 1
                return count

    def count_wins_in_year(self, year):
        count = 0
        for row in self.nfl:
            if row[2] == self.name and row[0] == year:
                count += 1
        return count

jaguars = Team("Jacksonville Jaguars")
jaguars_wins = jaguars.count_total_wins()
print(jaguars_wins)

niners = Team("San Francisco 49ers")
niners_wins_2013 = niners.count_wins_in_year("2013")
print(niners_wins_2013)
