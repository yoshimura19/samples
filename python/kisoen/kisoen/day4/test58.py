#!/usr/bin/env python
#coding:utf-8
#test58:正規表現の特殊文字とその他の細かい話

import re

 
# p = re.compile(正規表現)
# r = p.match(検索対象文字列)
# と等価な記法として
# import re
# r = re.match(正規表現，検索対象文字列)
# pat.match(“a”) != None  #matchしないということはなかったか？


p = re.compile("^(\d+)")
r = p.match("123+45=168")
print r.group(1)


a = (re.match("^ABC", "ABC") != None)
print(a)


def check_hit(p, s):
  r = p.search(s)
  if r == None:
    print "0"
  else:
    print "1"

pat = re.compile(r"(^AB|C)D(E|F$)")

check_hit(pat, "ABDENC")   #1
check_hit(pat, "ABDFC")    #0
check_hit(pat, "ABDX")     #0
check_hit(pat, "CDEX")     #1
check_hit(pat, "CDFX")     #0
check_hit(pat, "NCDEX")    #1
check_hit(pat, "NCDFX")    #0
check_hit(pat, "NABDE")    #0
check_hit(pat, "NABDF")    #0


pat = re.compile(r"^(\d+)$", re.MULTILINE)
print "START"
for r in pat.finditer("123\n45\n678"):
  print r.group(1)
print "END"
