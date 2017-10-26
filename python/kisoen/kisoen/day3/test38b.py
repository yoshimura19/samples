#coding:utf-8

file_name = raw_input()

try:
    f = open(file_name, "r")
    line_count = 0
    for l in f.readlines():
        line_count += 1
        print "%d: %s" % (line_count, l),

except IOError:
        print "ERROR"
