#include <iostream>

using namespace std;

/*
int max(int x, int y){
    if (x > y)
        return x;
    else
        return y;
}
*/
//int max(int x, int y) { return (x > y)? x : y; } 

//int max(int x, int y, int z) { return max(max(x, y), z); } 

int findMaxCrossArray (int arr[], int low, int mid, int high){     //based off of page 71 from textbook
    
    int leftSum = -99999;         //for negative infinity
    int sum = 0;
    //int maxLeft = 0;

    for (int i = mid; i >= low; i--){       //geting left side of array sum
        sum = sum + arr[i];
        if (sum > leftSum){
            leftSum = sum;
            //maxLeft = i;
    }
    }

    int rightSum = -99999;        //for negative infinity
    sum = 0;                     
    //int maxRight = 0;

    for (int j = mid + 1; j <= high; j++){      // geting right side of array sum
        sum = sum + arr[j];
        if (sum > rightSum){
            rightSum = sum;
            //maxRight = j;
    }
}
    int compare = leftSum + rightSum;       //adding up left and right side of sum
    //return (maxLeft, maxRight, leftSum + rightSum);
    return(compare);     //used to compare in FindMaxSubArray
}

/*
int findMaxSubSum(int *Arr, int start, int end){
    int maxSum = -99999;         
    int sum = 0;

    for (int i = start; i < end; i++){
        sum = sum + Arr [i];
        if (sum > maxSum){
            maxSum = sum;
    }
        return maxSum;
    }
    return 0;
}
*/


int findMaxSubArray(int arr[], int low, int high){     //based off of page 72 from textbook
    if (high == low){                                     //for only 1 element in array
        //return (low, high, Arr[low]);
        return arr [low];
    }
    //if (low < high){
    else {
    int mid = (low + high)/2;
    
    int leftSum = findMaxSubArray(arr, low, mid);           //find the 3 maxs in left, right, and cross
    int rightSum = findMaxSubArray(arr, mid + 1, high);
    int cross = findMaxCrossArray(arr, low, mid, high);

    //int leftMax = findMaxSubSum(arr, 0, mid);
    //int rightMax = findMaxSubSum(arr, mid + 1, high);
        /*
        int leftSum = -9999;        //for negative infinity
        int rightSum = -9999;       //for negative infinity
        int sum1 = 0;

        for (int i = 0; i < mid; i++){
            sum1 = sum1 + Arr[i];
            if (leftSum < sum1){
                leftSum = sum1;
            }
            else{
                    leftSum = sum1;
            }
        }

        int sum2 = 0;
        int rightStart = mid + 1;
        for (int i = rightStart; i < high; i++){
            sum2 = sum2 + Arr[i];
            if (rightSum < sum2){
                rightSum = sum2;
            }
            else { 
                rightSum = sum2;
            }
        }
        */
    
    if (leftSum > rightSum && leftSum > cross){
        return (leftSum);
    }
    else if (rightSum > cross){
        return (rightSum);
    }
    else 
        return (cross);
     
       
       //return max(leftSide, rightSide, cross);
       //return max(leftSide, rightSide, cross);
    //return max(max(max(leftMax, rightMax), cross), max(leftSide, rightSide));
    //}
    } 
}
int main(int argc, char **argv){
    
    int size = 0;
    cin >> size;                            // geting the size of the array
    int arr [size];

    for (int i = 0; i < size; i++){         // for getting elements(numbers) into array
        int elements;
        cin >> elements;
        arr[i] = elements;
    }

    //int sizeOfArr = sizeof(Arr)/sizeof(Arr[0]); //can't use .length since passed arguement, so have to get lenght that way

    cout << findMaxSubArray(arr, 0, size - 1);   //passing array, first index and last index

    //cout << maxSub;

    //return 0;
}