#coding:utf-8
#FizzBuzz問題

print("(最後の)数字Nを入力してください")
n = int(input())

print('\n')
for i in range(1,n+1):
    if i % 3 == 0 and i % 5 == 0:
        print("FizzBuzz")
    elif i % 3 == 0:
        print("Fizz")
    elif i % 5 == 0:
        print("Buzz")
    else:
        print("{0}".format(i))
