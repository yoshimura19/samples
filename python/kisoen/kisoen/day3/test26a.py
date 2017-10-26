#coding:utf-8

a = [0] * 10   #[0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
for i in range(10):
    a[i] = [i]
print a

for j in a:
    j[0] += 10
print j
print a
