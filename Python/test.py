list = ["Zebra", "cat", "Lion", "1rangotan", "Shark", "Bee", "BUll", "avestruz"]
sortedList = list.copy()
sortedList.sort(key=str.casefold)



print(list)
print(sortedList)