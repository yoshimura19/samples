#coding:utf-8

import time
import datetime

current_time = time.time()
print(current_time)

current_struct_time = time.gmtime(current_time)
current_hour = current_struct_time.tm_hour
current_mday = current_struct_time.tm_mday
print("current_mday:{0}".format(current_mday))
print("current_hour:{0}".format(current_hour))


current_datetime = datetime.datetime.now()
current_year = current_datetime.year
current_month = current_datetime.month
current_day = current_datetime.day
print("current_year:{0}, current_month:{1}, current_day:{2}".format(current_year, current_month, current_day))


today = datetime.datetime.now()
diff = datetime.timedelta(weeks = 3, days = 2)
result = today + diff
print(result)

diff = datetime.timedelta(days = 1)
yesterday = today - diff
tomorrow = today + diff
print("yesterday:{0}, tomorrow{1}".format(yesterday, tomorrow))

#today <- 2016-07-30 00:34:34.492709
today_formatted_string = today.strftime("%I:%M%p on %A %B %d, %Y")
print(today_formatted_string)

today_unformatted_string = datetime.datetime.strptime(today_formatted_string, "%I:%M%p on %A %B %d, %Y")
print(today_unformatted_string)
