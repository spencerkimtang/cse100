#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

/* I got helped from Ej Salcedo and he helpped me on doing radixSort with insertion sort
I needed help on how to inserttion sort on a 2D array, and he suggested combining all the arrays together
Also, after finishing insertion sort, I relaized a big mistake I made which was I was outputing the orginal array instead of the sorted array
So, my code for counting sort should work too.
/*

//Modified countingSort so it can work with radixSort(p.195)
//Looked online for help. Used stackoverflow
/*
void countingSort(int *arr, int size, int i){
    int C[size];
    int B[10] = {0}; //it is 10, because of the example input/output of Lab5 example has a length of 10
    int j = 0;
    
    for (j =0; i < size; i++){
        //B[(arr[j] / i) % 10] = B[(arr[j] / i) % 10] + 1;
        B[(arr[j] / i) % 10]++;
    }

    for (j = 1; j < 10; j++){
        B[j] = B[j] + B[j - 1];
    }

    //output array
    for (j = size - 1; j >= 0; j--){
        //B[ (arr[j] / i) % 10] = B[ (arr[j] / i) % 10] - 1;
        B[ (arr[j] / i) % 10]--;
    }

    //copies output array(C[]) to arr[], which have sorted numbers
    for (j = 0; j < size; j++){
        arr[j] = B[j];
    }
}
*/

//my insertion sort code from lab01
/*
    for (int i = 1; i < size; i++){         // i starts at index 1, since you compare the first to second
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key){     // based off of pseudocode on p.18
            arr[j + 1] = arr[j];            // swapping, the two numbers being compared
            j = j - 1;                      // for while loop if first iteration doesn't sort it 
           arr[j + 1] = key;               
        }
*/

void insertionSort(int **radix, int size, int i){
    int *arr = new int[10]; //makin an array in heap of size 10
    int key = 0;
    for(int j = 1; j < size; j++){
            key = radix[j][i]; 
        
        //instead of hard coding to combine the array together
        //Ej suggested that I try using it
        //memcpy combines arr, radix, and the size of radix in that order
        //Also we want to combine all the arrays, since insertion sort uses a single array to sort and doesn't have subarray
        memcpy(arr, radix[j], sizeof(**radix) * 10); //insert radixArray row[i] into our arr
        
        int k = 0;
        k = j - 1;
        
        while(k >= 0 && radix[k][i] > key){ 
            memcpy(radix[k + 1], radix[k], sizeof(**radix) * 10); 
            k = k - 1; 
        } 
        //sorted array
        memcpy(radix[k + 1], arr, sizeof(**radix) * 10);
    }
    //deletes the array on heap so it doesn't cause memory problems
    delete [] arr;
}

//based on textbook p.198
//I am going to use counting sort as my stable sort
//Since I have not used counting sort before I would like to use it
void radixSort(int **radix, int size){
    //geting max so we can know the number of digits
    /*
    int max = arr[0];
    for (int i = 1; i < size; i++){
        if (arr[i] > max)
            max = arr[i];
    }
    */

    //got stuck and my output from passing i as my digit wasn't working
    //went online to see why and I came across greeksforgreeks where they 
    //passed a varible that is 10^i instead of i
    // also is the reason for find the max
    
    //int digit;
    //for (digit = 1; max/digit > 0; digit = digit * 10){
    //for (digit = 1; max/digit > 0; digit *= 10){
    for (int i = 9; i >= 0; i--){
        insertionSort(radix, size, i);
    }
}

int main(int argc, char **argv){
    
    int size;
    cin >> size;                            // geting the number of rows for the 2d array

    int input = 0;
    int count = 0;

    //Declaring 2d array
    //Look at greeksforgreeks for how to declare 2d array(forgot how to)
    int arr[size][10];      //the "10" is for the size of columns
    for(int i = 0; i <  size; i++){
        for(int j = 0; j < 10; j++){
            if(count != 10){
                cin >> input;
                arr[i][j] = input;
            }
        }
    }

    int *radix[size];
    for(int i = 0; i < size; i++){
        radix[i] = new int[10];    
    }
    for(int i = 0; i < size; i++){
        for(int j = 0; j < 10; j++){
            radix[i][j] = arr[i][j];
        }
    }

    radixSort(radix, size);

    //Printing out 2d array after being sorteds
    for(int i = 0; i < size; i++){
        for(int j = 0; j < 10; j++){
            cout << radix[i][j] << ";";
        }
        cout << endl;
    }
    return 0;
}