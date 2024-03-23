import random

a = [random.randint(150, 200) for i in range(30)]

print(max(a) - min(a))

a.sort()
print(a)

a.sort(reverse=True)
print(a)