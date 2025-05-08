import random
import time


def dyskretna(x):
    if x > 0.6:
        if random.random() > 0.625:
            return 4, 2
        return 4, 3
    if x > 0.5:
        if random.random() > 0.5:
            return 3, 3
        return 3, 4
    if x > 0.4:
        return 2, 1
    if random.random() > 0.75:
        return 1, 4
    return 1, 2


def zad2():
    print("\nZad2:")
    tab = [[0 for _ in range(4)] for _ in range(4)]
    for _ in range(100000):
        x, y = dyskretna(random.random())
        tab[x-1][y-1] += 1

    print("X / Y-------------------------")
    for i in range(4):
        for j in range(4):
            print(i+1, "/", j+1, ":", tab[i][j])
        print("------------------------------")


random.seed(time.time())
zad2()

