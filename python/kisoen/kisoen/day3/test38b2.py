#coding:utf-8
#ファイルがopenできない時にはERRORを出力

file_name = raw_input()

count = 0
try:
    f = open(file_name, "r")
    for l in f.readlines():
        count += 1
        print "%s: %s" % (count, l),
except IOError:
        print "ERROR"
