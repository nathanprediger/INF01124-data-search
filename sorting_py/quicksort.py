#!/usr/bin/python3

def quicksort(arr) -> list:
    if len(arr):
        s = [i for i in arr[1:] if i < arr[0]]
        b = [i for i in arr[1:] if i >= arr[0]]

        return quicksort(s) + [arr[0]] + quicksort(b)
    
    return []

arr = [4,3,2,1,3,5,2,4,1,7,2,3,9,6,8,7,5,4,6,7,8,5,56,73,2,12,122,67,98,45,432,66,89,0,32]

print(arr)
print(quicksort(arr))
