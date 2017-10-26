#coding:utf-8

import re

pat = re.compile(r"^(\d+)$", re.MULTILINE)
print "START"
for r in pat.finditer("123\n45\n678"):
    print r.group(1)
print "END"

pat = re.compile(r"^(\d+)$")
print "START2"
for r in pat.finditer("123\n45\n678"):
    print r.group(1)
print "END"


