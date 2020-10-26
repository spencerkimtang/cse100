#include <stdio.h>
#include <limits.h>
#include<iostream>

using namespace std;

int cost[10][10], a, b, c, n, stk[10], top, v, visit[10], visited[10], u;

int main(){
    int i, j;
    cin >> n;
    cin >> i;
    for (c = 1; c <= i; c++){
        cin >> a >> b >> j;
        cost[a][b] = j;
    }
    for (a = 1; a <= n; a++){
        for (b = 1; b <= n; b++){
            if (cost[a][b] == 0){
                cout << "Order of visited vetices";
            }
        }
    }
    c = 1;
    while (c < n){
        for (a = 1; a <= n; a++){
            for (b = 1; b <= n; b++){
                if (cost [a][b] < i){
                    i = cost[a][b];
                    u = a;
                }
                else {
                    for (b = n; b >= 1; b--){
                        if (cost[a][b] < i && visited[b] != 1 && visit[b] != 1){
                            visit[b] = 1;
                            stk[top] = j;
                            top++;
                            i = cost[a][b];
                            u = b;
                        }
                    }
                    
                }
            }
        }
    }
}