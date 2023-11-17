import numpy as np

gamesList = np.array(["Tibia", "LOTRO", "World of Warcraft", "Age of Empires", "Diablo"])
gamesList.sort()
num = 1
for i in range(3):
    print (num,gamesList[i])
    num+=1