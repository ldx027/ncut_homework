lst = [1, 1, 3, 4, 5, 8, 13, 21, 34, 55, 89]
lst2 = []

for i in lst:
    if (i <= 5):
        print(i, end=" ")
        lst2.append(i)
        lst.remove(i)