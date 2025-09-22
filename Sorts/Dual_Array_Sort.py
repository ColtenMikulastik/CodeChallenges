

def dual_sorted_array(list_one, list_two):
    out = list()
    print("list one" + str(list_one))
    print("list two" + str(list_two))
    i = len(list_one) - 1
    j = len(list_two) - 1
    while i >= 0:
        while j >= 0:
            if list_one[i] >= list_two[j]:
                out.append(list_two.pop())
            else:
                break
            j -= 1
        out.append(list_one.pop())
        i -= 1

