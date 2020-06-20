def partition(array, start, end):
    pivot = array[end-1]
    pivot_index = start
    index = start
    
    while index < end-1:
        if array[index] <= pivot:
            """swap(array[index], array[pivot_index])"""
            temp = array[index]
            array[index] = array[pivot_index]
            array[pivot_index] = temp
            pivot_index += 1
        index += 1
    
    temp = array[pivot_index]
    array[pivot_index] = pivot
    array[end-1] = temp 
    
    return pivot_index
    
def quicksort(array, start, end):

    if start >= end:
        return

    pivot_index = partition(array, start, end)
    quicksort(array, start, pivot_index)
    quicksort(array, pivot_index + 1, end)

test = [21, 4, 1, 3, 9, 20, 25, 6, 21, 14]
quicksort(test, 0, len(test))
print test
