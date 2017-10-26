#coding:utf-8

import re

p0 = re.compile("^###(.*)")      #名前
p1 = re.compile("^Total (.*)")   #合計得点
p2 = re.compile("^[0-9]. (...)") #各問題得点
p3 = re.compile("(.*)分$")   #採点時間用
p4 = re.compile("^Note: (.*)")   #注記の集計

#f = open('採点メモ(HW1).txt', 'r')
f = open('採点個別(HW2).txt', 'r')

count = 0         #何人目か
total_time = 0    #採点時間

student_scores = {}
tyuki = {}
for l in f.readlines():
    r0 = p0.search(l)
    r1 = p1.search(l)
    r2 = p2.search(l)
    r3 = p3.search(l)
    r4 = p4.search(l)

    if p0.match(l) != None:
        score_prob = 0
        temp_name = r0.group(1)
        student_scores[temp_name] = "NA"

    if p2.match(l) != None:
        score_prob += float(r2.group(1)) #各問題点数足し上げ

    if p1.match(l) != None:             #合計得点格納 & 合計ミスcheck
        student_scores[temp_name] = r1.group(1)

        if float(r1.group(1)) != score_prob:
            print("\n足し上げミスかも\n{0}さんの合計点数は{1}\n".format(temp_name, score_prob))

    if p3.match(l) != None:
        total_time += int(r3.group(1))
        count += 1
        print("{0}人目 計{1}分".format(count,total_time))

    if p4.match(l) != None:
        tyuki[temp_name] = r4.group(1)

f.close



for k in sorted(student_scores.keys()):
    print("{0}, {1}".format(k, student_scores[k]))
print("")

for k in sorted(student_scores.keys()):
    print("{0}".format(student_scores[k]))

print("\nメモ:特に良いコードがあれば気に入ったものを１〜２点教えてください。\n")

for k in sorted(tyuki.keys()):
    print("{0}\n{1}\n".format(k, tyuki[k]))

print("採点時間{0}分".format(total_time))
