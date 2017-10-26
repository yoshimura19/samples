#coding:utf-8
#正規表現でくっつける　最初が"なら or 文字列の終端で終わる。 


import re

pat1 = re.compile('^"(.*)",(.*)$')
pat2 = re.compile('(.*),"(.*)"')


rows = []

try:
    while True:
        s = raw_input()
        rows.append(s)
except EOFError, e:
    pass

#print(rows)
for i in range(0, len(rows)):
    resultpat1 = pat1.search(rows[i])
    resultpat2 = pat2.search(rows[i])
    if resultpat1 != None:
        print "%s\t%s" % (resultpat1.group(1), resultpat1.group(2))
    elif resultpat2 != None:
        print "%s\t%s" % (resultpat2.group(1), resultpat2.group(2))
    else:
        temp = rows[i].replace(",","\t")
        print temp
