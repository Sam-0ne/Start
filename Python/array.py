#import numpy as np

gamesList = [
  'The Witcher 3: Wild Hunt',
  'Dark Souls III',
  'Final Fantasy XV',
  'Persona 5',
  'Diablo III',
  'Mass Effect 2',
  'Skyrim',
  'Dragon Age: Inquisition',
  'Monster Hunter: World',
  'NieR: Automata',
  'World of Warcraft',
  'Guild Wars 2',
  'Final Fantasy XIV',
  'Divinity: Original Sin 2',
  'Bloodborne',
  'Kingdom Hearts III',
  'Elder Scrolls Online',
  'Borderlands 3',
  'Path of Exile',
  'Star Wars: Knights of the Old Republic'
]

sortedList = gamesList.copy()
sortedList.sort(key=str.casefold)
#print (sortedList)
#print(gamesList)
for i in range(len(sortedList)):
    #print (i+1,". - ",sortedList[i], " - ", gamesList[i], sep="")
    print(f"{i+1}. - {gamesList[i]} ", f" - {sortedList[i]}", sep=" *  ===>>" )
    