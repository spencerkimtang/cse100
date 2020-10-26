#include <iostream>

using namespace std;


void merge( int arr [], int p, int q, int r){      //p= beginngin, q = middle, r = end based on textbook p.31
    int n1 = q - p + 1;                            // lower half
    int n2 = r - q;                                // higher half

    int left[n1];
    int right[n2];

    for (int i = 0;i < n1; i++){
        left[i] = arr[p + i];
    }

    for (int j = 0;j < n2;j++){
        right[j] = arr[q + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = p;

    while (i < n1 && j < n2){                   //used while since p.31 wasn't working for me, both is for sorting
        if (left[i] <= right[j]){
            arr[k] = left[i];
            //cout << arr[k] << " left" << endl;
            i = i + 1;
        }
        else {
            arr[k] = right[j];
            //cout << arr[k] << " right"<< endl;
            j = j + 1;
        }
        k++;
    }

    while(i < n1){                             //used for combining sorted lower half back into array
        arr[k] = left[i];
        i++;
        k++;
    }

    while(j < n2){                            //used for combining sorted higher half back into array with lower half from before while loop
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort (int arr[], int p, int r){   //p.34
    if (p < r){
        int q = (p + r)/2;
        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}


int main(int argc, char **argv){

    int size;
    cin >> size;                            // geting the size of the array
    int arr [size];

    for (int i = 0; i < size; i++){         // for getting elements(numbers) into array
        cin >> arr[i];
    }

    int sizeOfArr = sizeof(arr)/sizeof(arr[0]); //can't use .length since passed arguement, so have to get lenght that way

    mergeSort(arr, 0, sizeOfArr - 1);

    for (int i = 0; i < size; i++){       
        cout << arr[i] << ";";
    }
}