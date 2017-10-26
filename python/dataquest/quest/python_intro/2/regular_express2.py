#coding:utf-8

#データはaskreddit.pyのdata変数においた
import askreddit as ask
import re

posts_with_header = ask.data
posts = posts_with_header[1:]
#print(askreddit_data)

pat = re.compile("^[\[\(][Ss]erious[\]\)]")
pat2 = re.compile("[\[\(][Ss]erious[\]\)]$")
pat3 = re.compile("^[\[\(][Ss]erious[\]\)] | [\[\(][Ss]erious[\]\)]$")
#pat3はpat2 or pat1とした方が見やすいかも

serious_start_count = 0
serious_end_count = 0
serious_count_final = 0
for a_list in posts:
    result = pat.search(a_list[0])
    result2 = pat2.search(a_list[0])
    result3 = pat3.search(a_list[0])
    if result != None:
        serious_start_count += 1
    if result2 != None:
        serious_end_count += 1
    if result3 != None:
        serious_count_final += 1

print("文頭:{0}, 文末:{1}, 合計:{2}".format(serious_start_count, serious_end_count, serious_count_final))


####### Substituting Strings ########
posts_new = []
for a_list in posts:
    a_list[0] = re.sub("[\[\(][Ss]erious[\]\)]","[Serious]",a_list[0])
    posts_new.append(a_list)
#print(posts_new)


###### Matching Years ########
strings = ['War of 1812', 'There are 5280 feet to a mile', 'Happy New Year 2016!']

year_strings = []
for string in strings:
    #result = re.search("[1-2][0-9][0-9][0-9]", string)
    result = re.search("[1-2][0-9]{3}", string)
    if result != None:
        year_strings.append(string)
print(year_strings)


##### Extracting Years ######
years_string = "2015 was a good year, but 2016 will be better!"
years = re.findall("[1-2][0-9]{3}", years_string)
print(years)
