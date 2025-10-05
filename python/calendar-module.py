#Challenge- You are given a date. Your task is to find what the day is on that date.
import calendar as c

#take input in MM_DD_YYYY format
month, day, year = map(int, input().split())

#weekday() -> returns 0 (Monday) to 6 (Sunday)
day_index = c.weekday(year, month, day)

#to uppercase weekday name
day_name = c.day_name[day_index].upper()

print(day_name)