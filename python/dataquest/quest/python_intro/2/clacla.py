#coding:utf-8

import csv

f = open("nfl.csv", "r")
nfl = list(csv.reader(f))

class Team():
    def __init__(self):
        self.name = "Tampa Bay Buccaneers"

bucs = Team()
print(bucs.name)


class Team1():
    def __init__(self, name):
        self.name = name

giants = Team1("New York Giants")
print(giants.name)


class Team2():
    def __init__(self, name):
        self.name = name

    def print_name(self):
        print(self.name)

    def count_total_wins(self):
        wins = 0
        for rows in nfl:
            if self.name == rows[2]:
                wins += 1
        return(wins)

broncos = Team2("Denver Broncos")
broncos_wins = broncos.count_total_wins()
chiefs_wins = Team2("Kansas City Chiefs").count_total_wins()
print('{0} {1}'.format(broncos_wins, chiefs_wins))
#print(broncos_wins, chiefs_wins)
f.close()

