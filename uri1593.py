b = input()
for i in range(b):
	ans = 0
	a = input()
	while a != 0:
		ans = ans + 1
		a = a - (a&-a)
	print(ans)
