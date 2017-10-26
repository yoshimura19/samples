#coding:utf-8

l = []
b = 0
while b < 10:
        l.append(b)
        b = b + 1
b = 2
while b < 8:
    l.remove(b)
    b = b + 2
a = l[5]
print l
print a
