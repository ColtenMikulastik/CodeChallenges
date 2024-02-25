

def print_mat(matrix):
    for sub_list in matrix:
        print(sub_list)


matrix = []


# in_string = input("what would you like to have zig zagged?")
in_string = "bebadabadabobebadabadabobebad"

k = 4

cell_num = len(in_string) / ((k * 2) + 1)

across = round((cell_num * 4) + 1)

# make the matrix the right size for the program
for i in range(0, k):
    matrix.append([])
    for j in range(0, across):
        matrix[i].append(' ')


print(matrix)

index_x = 0
index_y = 0
do_go_up = False

for character in in_string:
    print_mat(matrix)
    print("-------------")
    matrix[index_x][index_y] = character
    if index_x == 0:
        do_go_up = False
    if index_x == (k - 1) or do_go_up:
        index_x = index_x - 1
        index_y = index_y + 1
        do_go_up = True
    else:
        index_x = index_x + 1


print_mat(matrix)
