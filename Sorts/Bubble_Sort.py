import my_random_utils

def bubble_sort(input_ar):
    print(input_ar)
    for i in range(len(input_ar)):
        # keep log of swaps per element
        swaps = 0
        for j in range(0, len(input_ar) - i - 1):
            # loop through a decreasing size array, assuming the largest element will be at the end
            if input_ar[j] > input_ar[j+1]:
                # if this element is greater than the next swap them
                temp = input_ar[j]
                input_ar[j] = input_ar[j+1]
                input_ar[j+1] = temp
                # iterate swaps
                swaps += 1
        if swaps == 0:
            break

def main(): 
    test = [2,6,5,4,7,1] 
    test = my_random_utils.random_list_int(100)
    bubble_sort(test) 
    print(test) 

if __name__ == "__main__":
    main()
