#coding:utf-8
#test.txtを開いて行数を数えて出力

count = 0
with open('test.txt', 'r') as f:
    for l in f.readlines():
        count += 1

print count
