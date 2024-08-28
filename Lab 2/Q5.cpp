/*
You're developing a program to manage a seating chart for a conference held in a hall with multiple rows
of seats. Each row has a different seat capacity. To efficiently handle the seating arrangements, you decide to use
a dynamic array. Implement a C++ code that allocates memory for the seating chart and allows attendees' names
to be inputted for each seat. Choose and implement the appropriate type of dynamic array for this scenario.
*/
#include <iostream>
#include <string>
using namespace std;

int main(){
    int numRows;
    cout << "Enter Number of Rows in the Theatre: " << endl;
    cin>> numRows;
    string **seats = new string*[numRows];
    int sizes[numRows] = {0};

    for (int i = 0; i<numRows; i++){
        cout << "Enter the Number of Seats in Row " << i+1 << endl;
        cin >> sizes[i];
    }

     for (int i = 0; i<numRows; i++){
            seats[i] = new string[sizes[i]];
     }

    cout << "Enter Names for All Seats:" << endl;
    for (int i = 0; i<numRows; i++){
        cout << "Enter Names for Row " << i+1 << endl;
        for(int j = 0; j<sizes[i]; j++){
            cin >> seats[i][j];
        }
    }

    cout << "Here's the Booking Arrangement: " << endl;
    for (int i = 0; i<numRows; i++){
        cout << "Row " << i+1 << endl;
        for(int j = 0; j<sizes[i]; j++){
            cout << " | " <<seats[i][j];
        }
        cout << endl;
    }


     for (int i = 0; i < numRows; i++) {
        delete[] seats[i];
    }

    delete[] seats;
    delete[] sizes;
    

    return 0;
}
