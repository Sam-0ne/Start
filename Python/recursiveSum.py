

def main ():    
    list = [1,2,3,4,5,6]    
    print(sum(list))
    return


def sum(int):    
    if not int:
        return 0
    return int[0] + sum(int[1:])

if __name__ == "__main__":
    main()