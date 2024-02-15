//Code Sample 1 Bubble Sort

#include<iostream>
using namespace std;

int main()
{
    int arr[] = {5, 3, 1, 9, 8, 2, 4, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << n << endl;

    // Bubble Sort
    for(int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // swap temp and arr[i]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // for printing
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}


//Code Sample 2
