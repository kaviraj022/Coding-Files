def insertionSort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1

        # Move elements of arr[0..i-1], that are
        # greater than key, to one position ahead
        # of their current position
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

arr = [64, 25, 12, 22, 11]

print("Original array: ", end="")
print(*arr)

insertionSort(arr)

print("Sorted array: ", end="")
print(*arr)