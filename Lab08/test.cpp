#include <iostream>

#include <climits>

using namespace std;

void printParenthesis(int i, int j, int n, int *brac, int &name)

{

    if (i == j)

    {

        cout << "A" << name++;

        return;

    }

    cout << "(";

    printParenthesis(i, *((brac + i * n) + j), n, brac, name);

//cout<<".";

    printParenthesis(*((brac + i * n) + j) + 1, j, n, brac, name);


cout << ")";

}

void matrixChainOrder(int arr[], int n)

{

    int arr1[n][n];

    int brac[n][n];

    for (int i = 1; i < n; i++)

        arr1[i][i] = 0;

    for (int L = 2; L < n; L++)

    {

        for (int i = 1; i < n - L + 1; i++)

        {

            int j = i + L - 1;

            arr1[i][j] = INT_MAX;

            for (int k = i; k <= j - 1; k++)

            {

                int q = arr1[i][k] + arr1[k + 1][j] + arr[i - 1] * arr[k] * arr[j];

                if (q < arr1[i][j])

                {

                    arr1[i][j] = q;

                    brac[i][j] = k;

                }

            }

        }

    }

    int name = 0;

    cout << arr1[1][n - 1] << endl;

    printParenthesis(1, n - 1, n, (int *)brac, name);

    cout << endl;

}

int main()

{

    int n, i;

    cin >> n;

    int *arr = new int[n + 1];

    for (i = 0; i <= n; i++)

    {

        cin >> arr[i];

    }

    matrixChainOrder(arr, n + 1);

    return 0;

}