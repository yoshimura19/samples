#coding:utf-8
#pythonの闇。Python2/3で挙動が違うがカタカナも一致している...

import re

pat = re.compile("[あ-ん]")
r1 = pat.match("う")
r2 = pat.match("漢")
r3 = pat.match("サ")

if r1 != None:
    print '"う"は一致'

if r2 != None:
    print '"漢"は一致'

if r3 != None:
    print '"サ"は一致'
