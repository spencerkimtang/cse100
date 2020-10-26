#include <iostream>
#include <stdlib.h> //for rand function

using namespace std;

//based on textbook on page 171
int partition(int arr [], int start, int end){
    int pivot = arr [end];
    int i = start - 1;
    for (int j = start; j <= end - 1; j++){
        if (arr[j] < pivot){
            i = i + 1;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[end]);
    return (i + 1);
}

//based on textbook page 179
int randomPartition(int arr[], int start, int end){
    int i = rand() % end + start;       // random range is start to end 
    swap(arr[end], arr[i]);
    return partition(arr, start, end);
}
//based on textbook on page 171
int quickSort(int arr [], int start, int end){
    if (start < end){
        int mid = partition(arr, start, end);
        quickSort(arr, start, mid - 1);
        quickSort(arr, mid + 1, end);
    }
}

int main(int argc, char **argv){

    //take in size of array
    int size;
    cin >> size;
    int arr [size];

    //takeing in elemens for array
    for (int i = 0; i < size; i++){
        int elements;
        cin >> elements;
        arr[i] = elements;
    }

    quickSort(arr, 0, size - 1);


    //prints out array after being sorted
    for (int j = 0; j < size; j++)
        cout << arr[j] << ";";
}