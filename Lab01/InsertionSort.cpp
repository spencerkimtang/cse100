#include <iostream>

using namespace std;

int main(int argc, char **argv){
    
    int size;
    cin >> size;
    int arr [size];

    for (int i = 0; i < size; i++){
        cin >> arr[i];
    }

    int key;        //from textbook p.16
    int j;

    for (int i = 1; i < size; i++){     //i starts at index 1, since you compare the first to second
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key){      //based off of pseudocode on p.18
            arr[j + 1] = arr[j];             // swaping
            j = j - 1;
           arr[j + 1] = key;
        }
        for (int k = 0; k <= i; k++){       //for outputting each completed sort
            cout << arr[k] << ";";
        }
        cout << endl;
    }

   /* for (int i = 0; i < size; i++){       //for regular output(print only final results)
        cout << arr[i] << ";";
    } */
}