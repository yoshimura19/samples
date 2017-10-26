#!/usr/bin/env python
#coding:utf-8

import re

pat = re.compile("<div class=\"faq_item\"><h5><a name=\d+></a>(.*?)<span")

number = 1
try: 
    while True:
        s = raw_input()
        result = pat.search(s)
        if result != None:
            question_str = result.group(1)
            replaced_string = re.sub(r'"(.*?)"', r'「\1」', question_str) #\1は1つ目の()中と交換
            print "%4d: %s" % (number, replaced_string)  #resultは0が一致した文字列全体 
            number += 1
except EOFError, e:                #1,..,nは一致した文字列のn番目の()の部分
    pass

