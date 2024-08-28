/*
You are tasked with developing a program to manage and display the Grade Point Average (GPA) for the
core courses offered in the first semester of four departments: Software Engineering (SE), Artificial Intelligence
(AI), Computer Science (CS), and Data Science (DS). Each department offers a distinct number of core courses
for this semester: SE has 3 core courses, AI has 4 core courses, CS has 2 core courses, and DS has 1 core course.
To efficiently store and present this data, which type of array structure would you employ? implement a solution
using the chosen array structure to display the GPAs of the core courses for each department.
*/

#include <iostream>
using namespace std;

int main(){
    
    int sizes[4] = {3, 4, 2, 1}; 
    float se[3] = {2.9, 3.3, 4}; 
    float ai[4] = {1.7, 2.3, 3.5, 2.9};
    float cs[2] = {1.33, 2.67};
    float ds[1] = {4};
    float *allGPA[4] = {se, ai, cs, ds};

    for(int i = 0; i<4; i++){
        cout << "GPA of Department " << i+1 << " :\n";
        for(int j = 0; j<sizes[i]; j++){
            cout << *(*(allGPA+i)+j) << endl;
        }
    }

    return 0;
}
