#include <iostream>
using namespace std;

int main(int argc, char **argv){
    
    int sizeofarray;                 //size of array
    int min;                       
    int max;

    cin >> sizeofarray;             //get size from user
    int array [sizeofarray];        // create array of size given from user

    for (int i = 0; i < sizeofarray; i++){
        cin >> array[i];
    }
    
    min = array[0];         // from yourid.cpp
    max = array[0];         // so code doesn't have to run check twice and start at second index

    for (int i = 1; i < sizeofarray; i++){      //from yourid.cpp
        if (array[i] > max){
        max = array[i];
        }
        if (array[i] < min){
        min = array[i];
        }
    }

    cout << max << ";" << min;
}