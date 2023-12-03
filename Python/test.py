
def main():
    list = ["Zebra", "cat", "Lion", "1rangotan", "Shark", "Bee", "BUll", "avestruz"]
    sortedList = list.copy()
    sortedList.sort(key=str.casefold)

    print(list)
    print(sortedList)
    print(get_int())

def get_int():
    while(True):
        try:
            x = int(input("Input an integer between 1 and 31:"))
            
        except ValueError:
                print("Value error. Input number from 1 up to 31.")
        except:
                print("Error.")
        else:
             if (x > 0) and (x < 32):
                return x
             else:
                pass




if __name__ == "__main__":
    main()