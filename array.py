# 1. Creating an array (list in Python)
my_array = [10, 20, 30, 40, 50]
print(f"Original Array: {my_array}")
# Output: Original Array: [10, 20, 30, 40, 50]

# ----------------------------------------------------

# 2. Accessing elements
# Arrays are zero-indexed: the first element is at index 0
first_element = my_array[0]
third_element = my_array[2]
last_element = my_array[-1] # Negative index accesses from the end
print(f"First element (index 0): {first_element}")
print(f"Third element (index 2): {third_element}")
print(f"Last element (index -1): {last_element}")
# Output: First element (index 0): 10
# Output: Third element (index 2): 30
# Output: Last element (index -1): 50

# ----------------------------------------------------

# 3. Modifying an element
my_array[1] = 25 # Change the element at index 1 (was 20)
print(f"Array after modification: {my_array}")
# Output: Array after modification: [10, 25, 30, 40, 50]

# ----------------------------------------------------

# 4. Adding elements
my_array.append(60) # Adds 60 to the end
my_array.insert(0, 5) # Inserts 5 at index 0 (the beginning)
print(f"Array after adding elements: {my_array}")
# Output: Array after adding elements: [5, 10, 25, 30, 40, 50, 60]

# ----------------------------------------------------

# 5. Removing elements
my_array.pop() # Removes and returns the last element (60)
my_array.remove(30) # Removes the first occurrence of the value 30
print(f"Array after removing elements: {my_array}")
# Output: Array after removing elements: [5, 10, 25, 40, 50]

# ----------------------------------------------------

# 6. Iterating through the array
print("Iterating through the array:")
for item in my_array:
    print(item * 2) # Print double the value of each item
