#include <iostream>
using namespace std;

int* bubbleSort(int myArr[], int size){
    int temp;
    bool swapped;
    
    for(int i = 0; i<size; i++){
        swapped = false;
        
        for(int j=0; j<size-i-1; j++){
            
            if(myArr[j] > myArr[j+1]){ //swapping
                temp = myArr[j];
                myArr[j] = myArr[j+1];
                myArr[j+1] = temp;
                swapped = true;
            }
        }

        if(!swapped){
            break;
        }

    }

    cout << "Array sorted using bubble sort: " << endl;

    for(int k = 0; k<size; k++){ //display sorted;
        cout << myArr[k] << endl;
    }

    return myArr;
}

int* selectionSort(int myArr[], int size){
    int temp;
    int minIndx;

    for(int i = 0; i<size; i++){
        minIndx = i;

        for (int j = i+1; j<size; j++){
            if (myArr[j] < myArr[minIndx]){
                minIndx = j;
            }
            if (minIndx != i){
                temp = myArr[minIndx];
                myArr[minIndx] = myArr[i];
                myArr[i] = temp;
            }
        }
    }

    cout << "Array sorted using Selection sort: " << endl;

    for(int k = 0; k<size; k++){ //display sorted;
        cout << myArr[k] << endl;
    }

    return myArr;
}

int* insertionSort(int myArr[], int size){

    int key;
    
    for(int i = 1; i<size; i++){
        key = myArr[i];
        int j = i-1;

        while(j >= 0 && myArr[j] > key){
            myArr[j+1] = myArr[j];
            j--;
        }
        myArr[j+1] = key;
    }

    cout << "Array sorted using Insertion sort: " << endl;

    for(int k = 0; k<size; k++){ //display sorted;
        cout << myArr[k] << endl;
    }

    return myArr;
}

int* shellSort(int myArr[], int size){
    
    for(int gap = size/2; gap > 0; gap /=2){
        for(int i = gap; i < size; i++){
            int temp = myArr[i];

            int j;
            for(j = i; j>= gap && myArr[j - gap] > temp; j -= gap){
                myArr[j] = myArr[j-gap];

            }
              myArr[j] = temp;
        }
    }

    cout << "Array sorted using Shell sort: " << endl;

    for(int k = 0; k<size; k++){ //display sorted;
        cout << myArr[k] << endl;
    }

    return myArr;
}

int getNextGap(int gap)
{
    // Shrink gap by Shrink factor
    gap = (gap*10)/13;

    if (gap < 1)
        return 1;
    return gap;
}

int* combSort(int a[], int n)
{
    int gap = n;
    bool swapped = true;

    while (gap != 1 || swapped == true)
    {
        gap = getNextGap(gap);
        swapped = false;


        for (int i=0; i<n-gap; i++)
        {
            if (a[i] > a[i+gap])
            {
                swap(a[i], a[i+gap]);
                swapped = true;
            }
        }
    }

    return a;
}

int main(){
   int Arr[7] = {23, 4, 54, 65, 12, 98, 1};

  bubbleSort(Arr, 7);
  selectionSort(Arr, 7);
  insertionSort(Arr, 7);
  shellSort(Arr, 7);
  combSort(Arr, 7);
  
    

}
