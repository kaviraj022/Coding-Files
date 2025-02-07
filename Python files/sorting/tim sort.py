MIN_RUN = 32  # Minimum size of a run


def insertion_sort(arr, left, right):
    """
    Sort the array segment arr[left:right+1] using insertion sort.
    """
    for i in range(left + 1, right + 1):
        key = arr[i]
        j = i - 1
        while j >= left and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key


def merge(arr, left, mid, right):
    """
    Merge two sorted segments of the array:
    - arr[left:mid+1]
    - arr[mid+1:right+1]
    """
    left_part = arr[left:mid + 1]
    right_part = arr[mid + 1:right + 1]

    i, j, k = 0, 0, left

    # Merge both parts until one is exhausted
    while i < len(left_part) and j < len(right_part):
        if left_part[i] <= right_part[j]:
            arr[k] = left_part[i]
            i += 1
        else:
            arr[k] = right_part[j]
            j += 1
        k += 1

    # Copy any remaining elements from the left part
    while i < len(left_part):
        arr[k] = left_part[i]
        i += 1
        k += 1

    # Copy any remaining elements from the right part
    while j < len(right_part):
        arr[k] = right_part[j]
        j += 1
        k += 1


def tim_sort(arr):
    """
    Perform Timsort on the given array.
    """
    n = len(arr)

    # Step 1: Sort small runs using insertion sort
    for start in range(0, n, MIN_RUN):
        end = min(start + MIN_RUN - 1, n - 1)
        insertion_sort(arr, start, end)

    # Step 2: Merge sorted runs iteratively
    size = MIN_RUN
    while size < n:
        for left in range(0, n, 2 * size):
            mid = min(left + size - 1, n - 1)
            right = min(left + 2 * size - 1, n - 1)

            if mid < right:
                merge(arr, left, mid, right)
        size *= 2


arr = [90, 35, 17, 42, 9, 23, 68, 4, 89, 12, 1]

print("Original array: ", end="")
print(*arr)

tim_sort(arr)

print("Sorted array: ", end="")
print(*arr)

