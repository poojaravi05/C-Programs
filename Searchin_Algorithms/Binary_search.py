def Binary_Search(arr, target):
    low = 0
    mid = 0
    high = len(arr)-1
    while (low <= high):
        mid = low + (high-low)//2
        if arr[mid] == target:
            return mid
        elif arr[mid] > target:
            high = mid-1
        else:
            low = mid+1
    return low

arr = [1, 2, 3, 5, 6, 7]
target = 4

res = Binary_Search(arr, target)

if arr[res] == target:
    print("Target found at index ", res)
else:
    print("Target not found. Supposed to be at index ", res)
