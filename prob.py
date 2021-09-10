x = 0;
a = [1, 1, 2, 3, 2, 5]
for i in a:
	x += i
y = a[0]
for i in (1, len(a) - 1):
	y = y - a[i]
print (x + y)
print(abs(y) - (x + y))