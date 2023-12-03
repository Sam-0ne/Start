
def main():
    array = [10,10,5,5,18,20,18,52,43,45,43,10,5,43]
    print(max(array, key=array.count))
    x = highest_rank(array)
    print(sorted(array,reverse=True))
    print(max(array, key=array.count))
    print(x)

def highest_rank(arr):
    return max(sorted(arr,reverse=True), key=arr.count)





if __name__ == "__main__":
    main()