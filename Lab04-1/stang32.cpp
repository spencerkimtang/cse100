#include <iostream>

using namespace std;

//based off of psudocode from textbook p.154
//the functions make "binary search tree"(larger number to the left and smaller to the right)
int maxHeapify(int *arr, int size, int i){
    int largest = i;
    int left = 2 * i;
    int right = (2 * i) + 1;
    //int size = sizeof(arr)/sizeof(arr[0]);

    if (left < size && arr[left] > arr[i])
        largest = left;
    
    //else 
      //  largest = i;

    if (right < size && arr[right] > arr[largest])
        largest = right;
        
    if (largest != i){
        swap(arr[i], arr[largest]);
        maxHeapify(arr, size, largest);
    }
}

//based off of psudocode from textbook p.157
//function makes max- heap
int buildMaxHeap(int *arr, int size){
    //int size = sizeof(arr)/sizeof(arr[0]);
    for (int i = size/2 -1; i >= 0; i--)
        maxHeapify(arr, size, i);
}

//based off of psudocode from textbook p.160
int heapSort(int *arr, int size){
    buildMaxHeap(arr, size);
    //int size = sizeof(arr)/sizeof(arr[0]);
    for (int i = size - 1; i >= 0; i--){
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}

int main(int argc, char **argv){

    int size = 0;
    cin >> size;
    // declaring pointer array because using regular wasn't working 
    int arr [size];

    //getting elements from user and putting it in array
    for (int i = 0; i < size; i++){
        int elements;
        cin >> elements;
        arr[i] = elements;
    }
    //passing the size of the array because makes the rest of the function easier/simplier to code
    heapSort(arr, size);
   
   // to print out array after sorting
    for (int j = 0; j < size; j++)
        cout << arr[j] << ";";
    //cout << sort;
}