#coding:utf-8
#!/usr/bin/env python


class Foo:
    pass

def hello(msg):
    print "Hello, " + msg + "!"

def goodbye(msg):
    print "Good-bye, " + msg + "!"


a = Foo()
a.xyz = 123
a.f = hello

b = Foo()
b.xyz = 456
b.f = goodbye

#print a.xyz
hello("masahiro")
a.f("hogehoge")
b.f("ggggg")



class Foo:         #関数定義や変数定義はクラスの中で出来る
    def __init__(self, name):      #第一引数にはインスタンスaが渡される
        self.name = name           #二つ目以降はuserが渡したもの

    def hello(self):
        print "Hello, " + self.name + "!"

    def goodbye(self):
        print "Good-bye, " + self.name + "!"


a = Foo("hogehoge")  #クラス名から実体（instance）を生成する
a.hello()
a.goodbye()
a.goodbye()
a.goodbye()
a.goodbye()




