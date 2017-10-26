#coding:utf-8
#正規表現を使った情報の抜き出しと文字列置換: 初級テスト

import re

pat = re.compile(r"Adding sequences from FASTA; added (\d+) sequences")

number = 1
try:
    while True:
        s = raw_input()
        result = pat.search(s)
        if result != None:
            #print(number)
            print result.group(1)
        if s == "END":
            break
except EOFError, e:
    pass

