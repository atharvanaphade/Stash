from datetime import date, timedelta


def solve(y):
    day = date(y, 1, 1)
    end = date(y, 12, 31)
    one_day = timedelta(days=1)
    while day < end:
        if day.weekday() == 4 and day.day == 13:
            yield day
        day += one_day

count = 0

for y in range (2001, 2100):
    for d in solve(y):
        count += 1

print(count)