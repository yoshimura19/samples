#coding:utf-8
#テスト48:inputファイルの中身を文字検索
#id 以外の時は単語レベルで検索？？

import re

input_file_name = raw_input()
searching_word = raw_input()
output_file_name = raw_input()

#pat = re.compile(searching_word)
id_pat = re.compile("id")
#id_pat = re.compile("id", re.I)    #IGNORECASE(大文字小文字区別しない)

with open(input_file_name, "r") as fin:
    with open(output_file_name, "w") as fout:
        line = 0
        hit = 0
        for l in fin.readlines():
            l = l.replace("\n","")
            line += 1
            id_case = id_pat.search(l)
            if id_case != None:    #検索単語がidのケース
                hit += 1
                print >> fout, ("line %d, hit #%d:   %s" % (line, hit, l))
            else:
                rows = l.replace(",",""); rows = rows.replace(".",""); #rows = rows.replace("\n","")
                rows = rows.split(" ")
                if searching_word in rows:
                    hit += 1
                    print >> fout, ("line %d, hit #%d:   %s" % (line, hit, l))
                    # result = pat.search(keyword)
                    # if result != None:
                    #     hit += 1
                    #     print >> fout, ("line %d, hit #%d:   %s" % (line, hit, l)),
