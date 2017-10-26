#coding:utf-8

f = open('test.txt', 'r')

count = 0
for l in f.readlines():
    count += 1

print count

f.close
