#coding:utf-8

import datetime
import askreddit as ask

posts_with_hedder = ask.data
posts = posts_with_hedder[1:]
#print(posts)

march_count = 0
for row in posts:
    temp = datetime.datetime.fromtimestamp(float(row[2]))
    row[2] = temp
    if row[2].month == 3:
        march_count += 1
print(march_count)

#上で全てtimestampに変換済み

def posts_count_per_month(month, posts):
    month_count = 0
    for row in posts:
        #temp = datetime.datetime.fromtimestamp(float(row[2]))
        #row[2] = temp
        if row[2].month == month:
            month_count += 1
    return month_count

feb_count = posts_count_per_month(2, posts)
aug_count = posts_count_per_month(8, posts)
print("feb_count:{0}, aug_count:{1}".format(feb_count, aug_count))
