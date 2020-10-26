#include<iostream>
#include<limits.h>
using namespace std;


int index = 0;
int index1 = 0;


int CutRod(int p[],int size){
   int i;
   int j;
   int position,temp[size+1];
   temp[0]=0;
  
   for( i = 1; i <= size; ++i){
       position = INT_MIN;
       for(j = 0; j < i; ++j){
           if(position < max(position, p[j] + temp[i-j-1]))
           {
               index = j;
               index1 = i - j - 1;
           }
           position = max(position, p[j] + temp[i-j-1]);
          }
       temp[i]=position;
   }
   return temp[size];
}

int main(){
   int n;
   cin>>n;
   int i=0;
   int p[n];
   while(i<n){
       cin >> p[i++];
   }
   cout << CutRod(p,n) << endl;
   cout << index + 1 << " " << index1 << " -1" << endl;
   return 0;
}