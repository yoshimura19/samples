#coding:utf-8
#FizzBuzz

i = int(raw_input())
j = int(raw_input())

count = 0
for count in range(i, j+1):
    if count % 3 == 0 and count %5 == 0:
        print "Fizz Buzz"
    elif count % 3 == 0:
        print "Fizz"
    elif count % 5 ==0:
        print "Buzz"
    else:
        print count
