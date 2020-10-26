#include <iostream>
#define MIN_INT -2147483647
using namespace std;

int FindMaxCrossArray(int arr[], int low, int mid, int high){
    int leftSum =  MIN_INT;
    int sum = 0;

    for(int i = mid; i >= low; i--){
        sum = sum + arr[i];
        if (sum > leftSum){
            leftSum = sum;
        }
    }

    int rightSum = MIN_INT;
    sum = 0;

    for(int j = mid + 1; j <= high; j++){
        sum = sum + arr[j];
        if (sum > rightSum){
            rightSum = sum;
        }
    }

    int sum1 = leftSum + rightSum;
    return (sum1);
}

int findMaxSubArray(int arr[], int low, int high){
    if (high == low)
        return arr[low];
    else{
    int mid = (low + high)/2;

    int leftSum = findMaxSubArray(arr, low, mid);
    int rightSum = findMaxSubArray(arr, mid + 1, high);
    int cross = FindMaxCrossArray(arr, low, mid, high);

    if (leftSum > rightSum && leftSum > cross)
        return (leftSum);
    else if (rightSum > leftSum)
        return (rightSum);
    else 
        return (cross);
    }
}

int main(int argc, char **argv){

    int *arr;
    int size = 0; 
    cin >> size;
    arr = new int [size];

    for (int i = 0; i <size; i++){
        int elements;
        cin >> elements;
        arr[i] = elements;
    }

    //int sizeOfArr = sizeof(arr)/sizeof(arr[0]);

    cout << findMaxSubArray(arr, 0, size -1);

    //cout << maxSub;

    //return 0;
}