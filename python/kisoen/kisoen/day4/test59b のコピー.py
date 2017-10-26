#coding:utf-8
#正規表現を使った情報の抜き出しと文字列置換: 中級テスト
#curl http://hgdownload.soe.ucsc.edu/downloads.html | python test59b.py

import re

pat = re.compile(r'<A HREF="\#.*">(.*?)</A>')
pat2 = re.compile(r'<B>.*(only)</B>')

number = 1
try:
    while True:
        s = raw_input()
        result = pat.search(s)
        result2 = pat2.search(s)    #終わり位置判定
        if result != None:
            #print(number)
            if result.group(1) == "<em>X. tropicalis</em>": continue #例外
            print result.group(1)
        if result2 != None:
            break
        if s == "END":     #実験のため
            break
except EOFError, e:
    pass

