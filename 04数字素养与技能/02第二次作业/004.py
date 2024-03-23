str = input("please enter your password: ")

flg = True

if (len(str) < 8):
    print("过短")
    flg = False
elif (len(str) > 16):
    print("过长")
    flg = False

haveNum = False
haveChar = False

for c in str:
    if (c.isdigit()):
        haveNum = True
    if (c.isalpha()):
        haveChar = True

if (not haveNum):
    print("没有数字")
    flg = False
if (not haveChar):
    print("没有字母")
    flg = False

if (flg):
    print("OK")
