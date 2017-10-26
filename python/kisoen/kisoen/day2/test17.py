#coding:utf-8

a = int(raw_input())
i = 1; j = 1

while 0 < a:
    print i
    b = a
    while 0 < b:
        print j
        print "F"
        b = b - 1
        j += 1
    a = a - 1
    i += 1
