matrix = [[112, 42, 83, 119],[56, 125, 56, 49],[15, 78, 101, 43],[62, 98, 114, 108]]
xl = len(matrix)
l = xl-1
sum = 0
for y in range (xl//2):
    for x in range (xl//2):
        sub = [(matrix[y][x]),(matrix[y][l-x]),(matrix[l-y][x]),(matrix[l-y][l-x])]
        print(sub)
        sub = max(sub)
        sum += sub
print(sum,"\n")        



for i in range(xl):
    print(matrix[i])