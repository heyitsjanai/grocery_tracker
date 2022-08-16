import re
import string

def dailyPurchasedItems():
    f = open('dailyPurchases.txt', 'r')
    data = f.read()
    f.close()

    words = data.split("\n")

    count = {}

    for word in words:
        if word in count:
            count[word] += 1
        else:
            count[word] = 1

    return count

def itemPurchaseFrequency(item):
    f = open('dailyPurchases.txt', 'r')
    data = f.read()
    f.close()

    words = data.split("\n")

    count = {}

    for word in words:
        if word in count:
            count[word] += 1
        else:
            count[word] = 1
    
    return count[item]

def dailyItemsHistogram():
    f = open('dailyPurchases.txt', 'r')
    data = f.read()
    f.close()

    words = data.split("\n")

    count = {}

    for word in words:
        if word in count:
            count[word] += 1
        else:
            count[word] = 1

    histogram = open("frequency.dat", "w")
    histogram.writelines(count)
    histogram.close()