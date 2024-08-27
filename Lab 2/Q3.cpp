/*Write a program that creates a 2D array of 5x5 values of type Boolean. Suppose indices represent people and the value at row i, column j of a 2D array is true just in case i and j are friends and
false otherwise. You can use initializer list to instantiate and initialize your array to represent the
following configuration: (* means “friends”)
i/j 0 1 2 3 4
0     *   * *
1   *   *   *
2     *
3   *       *
4   * *     *
Write a method to check whether two people have a common friend. For example, in the example above, 0 and 4
are both friends with 3 (so they have a common friend), whereas 1 and 2 have no common friends.
*/
#include <iostream>
using namespace std;

int main(){

    int person1, person2;
    bool hascommon= false;

    bool friendship[5][5] = {{false, true, false, true, true}, 
                            {true, false, true, false, true},
                            {false, true, false, false, false},
                             {true, false, false, false, true},
                             {true, true, false, true, false}};
    
    cout << "Enter Person 1(0-4): " << endl;
    cin >> person1;
    cout << "Enter Person 2(0-4): " << endl;
    cin >> person2;

    bool common[5]={false, false, false, false, false};

    for (int i = 0; i<5; i++){
        if (friendship[i][person1]){
            common[i] = true;
        }
    }

    for (int i = 0; i <5; i++){
        if (!friendship[i][person2]){
            common[i] = false;
        }
    }


    for(int i =0; i<5; ++i){
        if (common[i]){
            hascommon = true;
        }
    }

    if (hascommon){
    cout << "They have common friends. The common friends of person " << person1 << " and person " << person2 << " are:\n";
    for(int i =0; i<5; i++){
       if(common[i]){
        cout << i << endl;
       }
    }
    }else{
        cout << "Person " << person1 << " and Person " << person2 << " have no common friends."; 
    }

    return 0;
}
