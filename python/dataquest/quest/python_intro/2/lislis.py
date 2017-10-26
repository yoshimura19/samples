#coding:utf-8

#Enumerate
ships = ["Andrea Doria", "Titanic", "Lusitania"]
cars = ["Ford Edsel", "Ford Pinto", "Yugo"]

for i, ship in enumerate(ships):
    print("Iteration {0}\nShip name:{1}".format(i,ship))
    print("Cars name:{0}".format(cars[i]))


things = [["apple", "monkey"], ["orange", "dog"], ["banana", "cat"]]
trees = ["cedar", "maple", "fig"]

for i, thing in enumerate(things):
    thing.append(trees[i])
print(things)


#List Comprehensions
animals = ["Dog", "Tiger", "SuperLion", "Cow", "Panda"]

# animal_lengths = []
# for animal in animals:
#     animal_lengths.append(len(animal))
# print(animal_lengths)

animal_lengths = [len(animal) for animal in animals]
print(animal_lengths)

apple_prices = [100, 101, 102, 105]
apple_prices_doubled = [price * 2 for price in apple_prices]
apple_prices_lowered = [price - 100 for price in apple_prices]
print("doubled price:{0}, lowered price:{1}".format(apple_prices_doubled, apple_prices_lowered))



