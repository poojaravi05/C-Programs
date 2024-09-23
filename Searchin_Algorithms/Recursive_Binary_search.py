def rescursive_binary_search(arr, low, high, x):
    if high >= low:
        mid = low + (high - low) // 2
        if arr[mid] == x:
            return mid
        elif arr[mid] > x:
            return rescursive_binary_search(arr, low, mid-1, x)
        else:
            return rescursive_binary_search(arr, mid + 1, high, x)
    else:
        return -1

arr = [1, 2, 3, 5, 6, 7]
res = rescursive_binary_search(arr, 0, len(arr)-1, 7)
if res == -1:
    print("Target not found")
else:
    print("Target found at index ", res)