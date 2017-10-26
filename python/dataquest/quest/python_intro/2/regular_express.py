#coding:utf-8

#データはaskreddit.pyのdata変数においた
import askreddit as ask
import re

posts_with_header = ask.data
posts = posts_with_header[1:]
#print(askreddit_data)

pat = re.compile("of [Rr]eddit")   #またはre.search(regex, string)

of_reddit_count = 0
for a_list in posts:
    result = pat.search(a_list[0])
    if result != None:
        of_reddit_count += 1
print(of_reddit_count)


pat2 = re.compile("\[[sS]erious\]")

serious_count = 0
for a_list in posts:
    result2 = pat2.search(a_list[0])
    if result2 != None:
        serious_count += 1
print(serious_count)


pat3 = re.compile("[\[\(][Ss]erious[\]\)]")

serious_count = 0
for a_list in posts:
    result3 = pat3.search(a_list[0])
    if result3 != None:
        serious_count += 1
print(serious_count)
