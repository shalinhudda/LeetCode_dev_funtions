def binary_search(input_array, value):
    return recursive_binary_search(input_array, value, 0, len(input_array)-1)
    
def recursive_binary_search(input_array, value, start, end):
    center_index = (start+end)/2
    
    if value == input_array[center_index]:
        return center_index
    elif len(input_array[start:end]) == 0 or len(input_array[start:end]) == 1:
        return -1
    elif value > input_array[center_index]:
        return recursive_binary_search(input_array, value, center_index + 1, end)
    else:
        return recursive_binary_search(input_array, value, start, center_index - 1)

test_list = [1,3,9,11,15,19,29]
test_val1 = 25
test_val2 = 15
print binary_search(test_list, test_val1)
print binary_search(test_list, test_val2)