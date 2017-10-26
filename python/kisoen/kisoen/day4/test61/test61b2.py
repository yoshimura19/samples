#coding:utf-8
#dictionary_version(完成)
#提出の時は"\t"のsplitに注意

import csv
import sys

file_name1 = raw_input()
file_name2 = raw_input()
#file_name1 = "input1.tsv"
#file_name2 = "input2.tsv"

rows = []
gakusekibou = {}
with open(file_name1, "r") as f:              #名簿
    reader = csv.reader(f, delimiter='\t')
    for row in reader:
        rows = row[0].split("\t")   #もとのtsvファイルの作り方...手元では"\\t"
        gakusekibou[rows[0]] = rows[1]
#print(gakusekibou)

with open(file_name2, "r") as f2:
    reader = csv.reader(f2, delimiter='\t')
    for row in reader:
        rows = row[0].split('\t')
        if rows[0] in gakusekibou:
            rows.append(gakusekibou[rows[0]])
        print "\t".join(rows)

