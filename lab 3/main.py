import random
import time


def zad1():
    print("\nZad1:")
    tab = [0 for _ in range(10)]
    for _ in range(100000):
        x = random.random() * 100 + 50
        idx = (x - 50) // 10
        if x == 150:
            idx -= 1
        tab[int(idx)] += 1

    for i in range(0, 10):
        print(i * 10 + 50, "-", i * 10 + 59, ": ", tab[i])


def dyskretna(x):
    if x > 0.7:
        return 4
    if x > 0.2:
        return 3
    if x > 0.05:
        return 2
    return 1


def zad2():
    print("\nZad2:")
    tab = [0 for _ in range(4)]
    for _ in range(100000):
        tab[dyskretna(random.random())-1] += 1
    for i in range(0, 4):
        print(i, ": ", tab[i])


def losuj(ile_los):
    e = 0.0001
    f_max = 1 * 2 / 100
    a = (f_max - 0)/(150-50)
    b = f_max - a * 150
    while True:
        ile_los[0] += 1
        u1 = random.random() * 100 + 50
        u2 = (f_max + e) * random.random()
        f_u1 = a * u1 + b
        if u2 < f_u1:
            return int(u1)


def dod():
    print("\nDodatkowe:")
    ile_los = [0]
    losowania = [losuj(ile_los) for _ in range(100000)]
    tab = [0 for _ in range(10)]

    for i in losowania:
        idx = (i - 50) // 10
        if i == 150:
            idx -= 1
        tab[int(idx)] += 1
    for i in range(0, 10):
        print(i * 10 + 50, "-", i * 10 + 59, ": ", tab[i])
    print("Ilosc losowan: ", ile_los[0])


if __name__ == '__main__':
    random.seed(time.time())
    zad1()
    zad2()
    dod()

