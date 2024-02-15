# Python program demonstrating array operations: insert, update, delete, and search

# Initialize the array
arr = [1, 2, 3, 4, 5]
print("Initial array:", arr)

# Insert operation
arr.insert(2, 10)  # Insert 10 at index 2
print("Array after insertion:", arr)

# Update operation
arr[2] = 20  # Update element at index 2 to 20
print("Array after update:", arr)

# Delete operation
arr.pop(2)  # Remove element at index 2
print("Array after deletion:", arr)

# Search operation
search_element = 4
if search_element in arr:
    index = arr.index(search_element)
    print(f"Element {search_element} found at index:", index)
else:
    print(f"Element {search_element} not found in the array.")

