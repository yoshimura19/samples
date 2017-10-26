#coding:utf-8
#正規表現を使った情報の抜き出しと文字列置換: 中級テスト
#curl http://hgdownload.soe.ucsc.edu/downloads.html | python test59b.py
#curl http://hgdownload.soe.ucsc.edu/downloads.html > USUC



import re

#start_pat = re.compile(r'<B>.*(Complete).*</B>')
pat = re.compile(r'<A HREF="\#.*">(.*?)</A>')
pat2 = re.compile(r'<B>.*(only)</B>')
exclude_pat = re.compile(r'<em>.*</em>')     #emが斜体なので除く

number = 1
try:
    while True:
        s = raw_input()
        result = pat.search(s)
        result2 = pat2.search(s)    #終わり位置判定
        exclude = exclude_pat.search(s)
        if result != None:
            #if result.group(1) == "<em>X. tropicalis</em>": continue #例外
            if exclude != None: continue
            print result.group(1)
        elif result2 != None:
            break
except EOFError, e:
    pass




