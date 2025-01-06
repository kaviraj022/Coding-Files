def quick_sort(arr, low, high):
    # Base condition: If the segment has at least two elements
    if low < high:
        # Partition the array and get the pivot index
        pivot_index = partition(arr, low, high)

        # Recursively sort the elements before and after the pivot
        quick_sort(arr, low, pivot_index - 1)  # Sort left part
        quick_sort(arr, pivot_index + 1, high)  # Sort right part


def partition(arr, low, high):
    """
    Partitions the array into two segments based on a pivot element.
    """
    # Choose the last element as the pivot
    pivot = arr[high]  # choosen based on the scenario
    # Pointer for the position where the next smaller element should be placed
    i = low

    # Iterate over the segment from 'low' to 'high - 1'
    for j in range(low, high):
        # If the current element is less than the pivot
        if arr[j] < pivot:
            # Swap the current element with the element at pointer 'i'
            arr[i], arr[j] = arr[j], arr[i]
            i += 1  # Increment the pointer for smaller elements

    # After the loop, place the pivot element in its correct position
    arr[i], arr[high] = arr[high], arr[i]
    # Return the index of the pivot element
    return i


arr = [64, 25, 12, 22, 11]

print("Original array: ", end="")
print(*arr)

quick_sort(arr, 0, len(arr) - 1)

print("Sorted array: ", end="")
print(*arr)
