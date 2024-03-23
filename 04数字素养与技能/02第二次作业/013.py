import random

num = random.randint(0, 100)

ply1 = [input("玩家1昵称:"), int(input("玩家1数字:"))]
ply2 = [input("玩家2昵称:"), int(input("玩家2数字:"))]

if (abs(ply1[1] - num) < abs(ply2[1] - num)):
    print("{}胜利".format(ply1[0]))
elif (abs(ply1[1] - num) > abs(ply2[1] - num)):
    print("{}胜利".format(ply2[0]))
else:
    print("平局")