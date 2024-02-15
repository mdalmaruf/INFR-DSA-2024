#include <iostream>
#include <vector>
#include <algorithm>  // for std::find and std::distance

int main() {
    // Initialize the array
    std::vector<int> arr = {1, 2, 3, 4, 5};
    std::cout << "Initial array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Insert operation
    arr.insert(arr.begin() + 2, 10);  // Insert 10 at index 2
    std::cout << "Array after insertion: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Update operation
    arr[2] = 20;  // Update element at index 2 to 20
    std::cout << "Array after update: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Delete operation
    arr.erase(arr.begin() + 2);  // Remove element at index 2
    std::cout << "Array after deletion: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Search operation
    int search_element = 4;
    auto it = std::find(arr.begin(), arr.end(), search_element);
    if (it != arr.end()) {
        std::cout << "Element " << search_element << " found at index: " << std::distance(arr.begin(), it) << std::endl;
    } else {
        std::cout << "Element " << search_element << " not found in the array." << std::endl;
    }

    return 0;
}
