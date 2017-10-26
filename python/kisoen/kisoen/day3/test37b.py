#coding:utf-8
#友だちが多いひとを出力
# John
# Fred
# Anne
# Bill
# Fred
# Bill
# John
# Bill
# Gusfield
# Robinson
# END


#print "Input friends>",
friends_dict = {}

while True:
    for i in range(0,2):
        person1 = raw_input()
        person2 = raw_input()
        if person2 == "END": break    #ENDという名前はいない
        if not person1 in friends_dict:  #1人目と２人目の名前がいたかどうか。
            friends_dict[person1] = 1
        else:
            friends_dict[person1] += 1
        if not person2 in friends_dict:
            friends_dict[person2] = 1
        else:
            friends_dict[person2] += 1
    if person2 == "END": break

temp = 0; max_person = "a"
for key in friends_dict.keys():
    if temp < friends_dict[key]:
        temp = friends_dict[key]
        max_person = key

print "%s %s" % (max_person, friends_dict[max_person])

