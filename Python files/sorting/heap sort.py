"""
Remember
Dont verify with online implementation, Taught by sachin
"""


def heapify(arr, n):
    for i in range(n // 2 - 1, -1, -1):
        parent = i
        while True:
            left_child = 2 * parent + 1
            right_child = 2 * parent + 2
            if left_child < n and right_child < n:
                child = (
                    left_child if arr[left_child] > arr[right_child] else right_child
                )
            elif left_child < n:
                child = left_child
            else:
                break
            if arr[child] > arr[parent]:
                arr[child], arr[parent] = arr[parent], arr[child]
                parent = child
            else:
                break


def heap_sort(arr):
    n = len(arr)
    heapify(arr, n)
    for i in range(n - 1, -1, -1):
        arr[0], arr[i] = arr[i], arr[0]
        heapify(arr, i)


arr = [90, 35, 17, 42, 9, 23, 68, 4, 89, 12, 1]

print("Original array: ", end="")
print(*arr)

heap_sort(arr)

print("Sorted array: ", end="")
print(*arr)
