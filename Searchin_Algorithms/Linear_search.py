def linear_search(arr, target):
    for i in range(0, len(arr)):
        if arr[i] == target:
            return i
    return None

def verify(index):
    if index is not None:
        print("Target found at index: ", index)
    else:
        print("Target not found")

arr = [10, 7, 9, 8, 1, 4, 2, 3]

res = linear_search(arr, 12)
verify(res)