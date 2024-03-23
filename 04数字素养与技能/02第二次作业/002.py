import time

t = time.localtime()

name = input("请输入姓名: ")
age = int(input("请输入年龄: "))
print("Hello {}, in year {}, you will be 100 years old.".format(name, 100 - age + t.tm_year))