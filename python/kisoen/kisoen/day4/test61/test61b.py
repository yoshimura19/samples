#coding:utf-8

import csv
import sys

#f = open("input1.tsv", "r")
#f2 = open("input2.tsv", "r")

file_name1 = raw_input()
file_name2 = raw_input()

rows = []
input1 = [] ;input1_num = 0
input2 = []
with open(file_name1, "r") as f:              #名簿
    reader = csv.reader(f, delimiter='\t')
    for row in reader:
        rows = row[0].split("\\t")   #もとのtsvファイルの作り方...手元では"\\t"
        input1.append(rows)
        input1_num += 1

with open(file_name2, "r") as f2:
    reader = csv.reader(f2, delimiter='\t')
    for row in reader:
        rows = row[0].split('\\t')
        input2.append(rows)

for row in input2:
    for j in range(0, input1_num):    #学籍番号が名簿と一致したら
        if row[0] == input1[j][0]:
            row.append(input1[j][1])
            print "\t".join(row)
