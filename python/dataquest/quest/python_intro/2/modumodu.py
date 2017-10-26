#coding:utf-8

import csv

f = open("nfl.csv")
csvreader = csv.reader(f)
#print(csvreader)
nfl = list(csvreader)   #python2では動かない
print(nfl)

count = 0
for list in nfl:
    if list[2] == "New England Patriots":
        count += 1
patriots_wins = count
#print(patriots_wins)


def nfl_wins(team_name):
    wins = 0
    for list in nfl:
        if list[2] == team_name:
            wins += 1
    return wins

cowboys_wins = nfl_wins("Dallas Cowboys")
falcons_wins = nfl_wins("Atlanta Falcons")
#print(cowboys_wins, falcons_wins)


def nfl_wins_in_a_year(team_name, year):
    wins = 0
    for list in nfl:
        if list[2] == team_name and list[0] == year:
            wins += 1
    return wins

brown_2010_wins = nfl_wins_in_a_year("Cleveland Browns", "2010")
eagles_2011_wins = nfl_wins_in_a_year("Philadelphia Eagles", "2011")
print(brown_2010_wins, eagles_2011_wins)    #使用csvは2009データのみ
