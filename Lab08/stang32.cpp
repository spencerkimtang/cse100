#include <iostream>
#include <climits>

using namespace std;

//I watched this video https://www.youtube.com/watch?v=GMzVeWpyTN0 along with other
//This video was the most helpful
//I learned how matrix chain multiply works and got ideas on how to code it from the video


//based on page 377
void print(int i, int j, int size, int *B, int &position){
    if (i == j){
        cout << "A" << position++;
        return;
    }
    cout << "(";
    print(i, *((B + i * size) + j), size, B, position);
    print(*((B + i * size) + j) + 1, j, size, B, position);
    cout << ")";
}



//based on page 371
//I also had to look up on how to multiply matrix in code again
void matrixMultiply(int arr [], int size){
    int A[size][size];
    int B[size][size];

    for (int i = 1; i < size; i++){
        A[i][i] = 0;
    }

    for (int j = 2; j < size; j++){
        for (int i = 1; i < size - j + 1;i++){
            int k = i + j - 1;
            A[i][k] = INT_MAX;
            for (int x = i; x <= k - 1; x++){
                int q = A[i][x] + A[x + 1][k] + arr[i - 1] * arr[x] * arr[k];
                if (q < A[i][k]){
                    A[i][k] = q;
                    B[i][k] = x;
                }
            }
        }
    }

    int position = 0;
    cout << A[1][size - 1] << endl;
    print(1, size - 1, size, (int *)B, position);
    cout << endl;
}

int main(){
    int size;
    cin >> size;

    int i;
    int *arr = new int [size + i];

    for (i = 0; i <= size; i ++){
        int elements;
        cin >> elements;
        arr[i] = elements; 
    }
    matrixMultiply(arr, size + 1);
    return 0;
}