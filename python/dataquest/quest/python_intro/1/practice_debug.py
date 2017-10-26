#coding:utf-8

print("input a probability of heads>"),
prob = float(raw_input())


def flip_coin(heads_probability):
    if heads_probability >= 0.5:
        return("Heads")
    else:
        return("Tails")

print(flip_coin(prob))
