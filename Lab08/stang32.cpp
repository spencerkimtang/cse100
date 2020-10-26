#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>

using namespace std;

//Got help from varies online sources like stackover flow and greeksforgreeks
//didn't know what header files to use, also needed help using the arrow operator

struct Min_Heap_Node {
char data;
unsigned freq;

//for children
Min_Heap_Node *left, *right;

Min_Heap_Node(char data, unsigned freq){

left = right = NULL;
this->data = data;
this->freq = freq;
}
};

//comparing 2 nodes
struct compare {
bool operator()(Min_Heap_Node* l, Min_Heap_Node* r){

return (l->freq > r->freq);
}
};

// Prints huffman codes
void printCodes(struct Min_Heap_Node* root, char ans , string str){
if (!root){
    return;
}

if (root -> data != '$'){
if(ans == root -> data){
cout << root -> data << ":" << str << endl;
}
}

printCodes(root->left,ans, str + "0");
printCodes(root->right,ans, str + "1");

}

//builds the tree
void Huffman(char data[], int freq[], int size){
struct Min_Heap_Node *left, *right, *top;

//makes min heap and stores in data array
priority_queue<Min_Heap_Node*, vector<Min_Heap_Node*>, compare> minHeap;

for (int i = 0; i < size; ++i){
minHeap.push(new Min_Heap_Node(data[i], freq[i]));
}

//get the 2 min numbers
while (minHeap.size() != 1){

left = minHeap.top();
minHeap.pop();
right = minHeap.top();
minHeap.pop();

// Makes another node that is the sum of childern node
//and then add the new node to min heap
top = new Min_Heap_Node('$', left->freq + right->freq);
top->left = left;
top->right = right;
minHeap.push(top);
}

//printing out codes
for(int i = 0;i <= 5; ++i){
printCodes(minHeap.top(),data[i], "");
}
}

int main(){

char arr[] = { 'A', 'B', 'C', 'D', 'E', 'F' };
//int freq[] = { 15, 11, 5, 1, 2, 4};

int times;
int freq[5];

//getting inputs of frequency for each character
for (int i = 0; i <= 5; i++){
    cin >> times;
    freq[i] = times; 
} 

int size = sizeof(arr) / sizeof(arr[0]);

Huffman(arr, freq, size);

return 0;
}