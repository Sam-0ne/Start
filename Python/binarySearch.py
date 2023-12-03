
def main():
    my_list = [1, 2, 3, 4, 5, 7, 8, 10]
    item = int(input("Search for number:"))
    index = pesquisa_binaria(my_list, item)
    if index == None:
        print(f"{item} was not found at list.")
    else:
        print(f"Number {item} is at index {index}")


def pesquisa_binaria(list, item):
    low = 0
    high = len(list) - 1
    while not (low > high):
        middle = (high + low) // 2        
        guess = list[middle]
        if guess == item:
            return middle
        if guess > item:
            high = middle - 1
        else:
            low = middle + 1            
    return None


if __name__ == "__main__":
    main()