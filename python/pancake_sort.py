def reverse_prefix(number_list, end_index):
    start_index = 0
    while start_index < end_index:
        number_list[start_index], number_list[end_index] = number_list[end_index], number_list[start_index]
        start_index += 1
        end_index -= 1

def pancake_sort(numbers):
    num_elements = len(numbers)

    for unsorted_size in range(num_elements, 1, -1):
        
        sub_list = numbers[:unsorted_size]
        index_of_max = sub_list.index(max(sub_list))
        
        last_index_of_unsorted = unsorted_size - 1

        if index_of_max != last_index_of_unsorted:
           
            if index_of_max != 0:
                reverse_prefix(numbers, index_of_max)
            reverse_prefix(numbers, last_index_of_unsorted)
            
    return numbers

first_list = [23, 10, 20, 11, 12, 6, 7]
print(f"Original: {first_list}")

pancake_sort(first_list)
print(f"Sorted:   {first_list}")


second_list = [5, 2, 8, 1, 9, 4]
print(f"\nOriginal: {second_list}")

sorted_list = pancake_sort(second_list)
print(f"Sorted:   {sorted_list}")