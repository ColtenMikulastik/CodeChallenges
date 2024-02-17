

matrix = []


in_string = input("what would you like to have zig zagged?")

k = 4

cell_num = len(in_string) / ((k * 2) + 1)

across = round((cell_num * 4) + 1)

# make the matrix the right size for the program
for i in range(0, k):
    matrix.append([])
    for j in range(0, across):
        matrix[i].append(' ')


print(matrix)

# index_x = 0
# index_y = 0
#
# for character in in_string:
#     matrix[index_x][index_y] = character
