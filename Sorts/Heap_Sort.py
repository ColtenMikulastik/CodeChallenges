

"""
this code was originally taken from https://www.geeksforgeeks.org/dsa/heap-sort/
with some minor changes, and notes written by me :^)
"""

def heapify(arr, n, i):
    """i is the value of root, n is size of tree, recursive"""
    # Initialize largest as root
    largest = i 
    # left or right, using priciple of
    # left node = 2*index
    # right node = 2*index + 1
    left = 2 * i + 1 
    right = 2 * i + 2

    # If left child is larger than root
    if left < n and arr[left] > arr[largest]:
        largest = left

    # If right child is larger than largest (overwriting left)
    if right < n and arr[right] > arr[largest]:
        largest = right

    # If largest is not root swap values
    if largest != i:
        temp = arr[i] 
        arr[i] = arr[largest]
        arr[largest] = temp
        # Recursively call on sub tree
        heapify(arr, n, largest)

def heap_sort(arr):
    """takes array, drives repeated removal of root and heapify calls"""
    n = len(arr) 
    # build initial heap for tree, recursively
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

    # repeatedly remove root from tree
    for i in range(n - 1, 0, -1):
        # swap root and end -> bigest with smallest in heap
        temp = arr[0]
        arr[0] = arr[i]
        arr[i] = temp
        # reheapily on the heap after removal of node
        heapify(arr, i, 0)

def main():
    test = [5,4,6,8,4,3,6,8,5,3]
    # initial call of heapsort
    heap_sort(test)
    print(test)
    return

if __name__ == "__main__":
    main()
