# Create a dictionary
student_info = {
    "name": "Alice",
    "age": 20,
    "major": "Computer Science",
    "gpa": 3.8
}

print("Original student information:")
print(student_info)

# Accessing values
print(f"\nStudent's name: {student_info['name']}")
print(f"Student's major: {student_info['major']}")

# Adding a new key-value pair
student_info["university"] = "State University"
print("\nAfter adding university:")
print(student_info)

# Modifying a value
student_info["gpa"] = 3.9
print("\nAfter updating GPA:")
print(student_info)

# Removing a key-value pair
removed_item = student_info.pop("age")
print(f"\nAfter removing age: {student_info}")
print(f"Removed item (age): {removed_item}")

# Iterating through keys
print("\nAll keys in the dictionary:")
for key in student_info:
    print(key)

# Iterating through values
print("\nAll values in the dictionary:")
for value in student_info.values():
    print(value)

# Iterating through key-value pairs
print("\nAll key-value pairs:")
for key, value in student_info.items():
    print(f"{key}: {value}")

# Checking if a key exists
if "major" in student_info:
    print("\n'major' key exists in the dictionary.")

# Getting the length of the dictionary
print(f"\nLength of the dictionary: {len(student_info)}")

# Clearing the dictionary
student_info.clear()
print(f"\nAfter clearing the dictionary: {student_info}")