#coding:utf-8

class Hogehoge:
    def __init__(self, value):
        self.value = value

    def plus(self, value):
        return self.value + value


a = Hogehoge(10)
print a.plus(15)
print a.plus(-3)


class Mathconst:
    PI = 3.14159
    e = 2.71828

b = Mathconst
print b.PI
print b.e
