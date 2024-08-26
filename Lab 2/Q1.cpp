//Implement Jagged arrays by taking a size of 5. Then, resize it to 10 in each index.

#include <iostream>
using namespace std;

int main() {
    int **arr = new int*[5];
    int Size[5];
    int i, j;

    // Allocate memory for the rows and take input for sizes
    for (i = 0; i < 5; i++) {
        cout << "Row " << i + 1 << " size: ";
        cin >> Size[i];
        arr[i] = new int[Size[i]];
    }

    // Take input for elements of the array
    for (i = 0; i < 5; i++) {
        for (j = 0; j < Size[i]; j++) {
            cout << "Enter row " << i + 1 << " elements: ";
            cin >> arr[i][j];
        }
    }

    cout << "Resizing all columns to 10\n" << endl;

    // Create a new array with each row of size 10
    int **newarr = new int*[5];

    for (i = 0; i < 5; i++) {
        newarr[i] = new int[10];
         for (j = 0; j < 10; j++) {
            newarr[i][j] = 0;  // Initialize with 0
        }
    }

    // Copy existing elements to the new array
    for (i = 0; i < 5; i++) {
        for (j = 0; j < Size[i]; j++) {
            newarr[i][j] = arr[i][j];
        }
    }

    // Deallocate old memory
    for (i = 0; i < 5; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    // Point arr to newarr
    arr = newarr;

    // Optionally, you can now use `arr` for further processing

    // Cleanup before exiting
    for (i = 0; i < 5; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
