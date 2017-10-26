#coding:utf-8
#csvモジュールver

import csv
import StringIO  #文字列をCSVとして処理
import sys

#f = open(sys.argv[0], "r")

output = []
try:
    while True:
        s = raw_input()
        fh = StringIO.StringIO(s)   #擬似的なファイルを作成
        reader = csv.reader(fh)
        for row in reader:
            output.append(row)
except:
    pass

    for individual in output:
        print "\t".join(individual)
