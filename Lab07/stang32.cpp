#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;


//Collaborated with Malia Bowman

int size;
int rodSize;

//based off of psuedocode from textbook
int CutRod(int vals[], int A[]) {
	int val[size + 1];
	int lastRod[size + 1];
	val[0] = 0;
	int i = 1;
	int j = 0;

	for (i = 1; i <= size; i++) {
		int position = -1;
		int max = INT_MIN;  
		
		for (j = 0; j < i; j++) {
			if (max < vals[j] + val[i - j - 1]) {
				position = j;
				max = vals[j] + val[i - j - 1];
			}
		}
		
		val[i] = max;
		lastRod[i] = position + 1;
	}
	i = size;
	j = 0;
	
	while (i > 0) {
		A[j++] = lastRod[i];
		i = i - lastRod[i];
	}
	
	rodSize = j;
	return val[size];
}

int main() {
    cin >> size;
    int vals[size];

    for (int i = 0; i < size; i++) {
        cin >> vals[i];
    }

    int arr[size + 1];

    int q = CutRod(vals, arr);
    cout << q << endl;
    cout << arr[0];

    for (int i = 1; i < rodSize; i++) {
        cout << " " << arr[i];
    }
	
    cout << " -1" << endl;
    return 0;
}