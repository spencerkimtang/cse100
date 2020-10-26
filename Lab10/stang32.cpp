#include <iostream>
#include <list>
#include <stack>

using namespace std;

//Got help from Thomas Moua as looked online for help from greekforgreek, chegg, and stackoverflow
//Also watch youtube videos on how the code should work. They also gave examples

class Graph {
// Declare the vertex
int vertex2;
// Declare a list od adjacent node
list<int> *adjacent;
//filling in node
void fillIn(int vertex, bool visited[], stack<int> &Stack);
//DFS to transeverse through 
void DFS(int vertex, bool visited[],int node,int ar[]);

public:
Graph(int vertex2);
void addEdge(int vertex, int w);
//print function
void print(int node,int arr[]);
Graph getTranspose();
};

Graph::Graph(int vertex2){
//tranverse the vertex
this -> vertex2 = vertex2;
// traverse the adjacent vertex
adjacent = new list<int>[vertex2];
}

//display DFS
void Graph::DFS(int vertex, bool visited[], int node, int arr[]){  
visited[vertex] = true;
arr[vertex] = node;
list<int>::iterator i;

for (i = adjacent[vertex].begin(); i != adjacent[vertex].end(); ++i){
    if (!visited[*i]){
    DFS(*i, visited, node, arr);
    }
}
}

Graph Graph::getTranspose(){
Graph g(vertex2);
for (int vertex = 0; vertex < vertex2; vertex++){
    list<int>::iterator i;
    for(i = adjacent[vertex].begin(); i != adjacent[vertex].end(); ++i){
        g.adjacent[*i].push_back(vertex);
    }
}
return g;
}

//add to SCC
void Graph::addEdge(int vertex, int w){
adjacent[vertex].push_back(w);
}

//filling node
void Graph::fillIn(int vertex, bool visited[], stack<int> &Stack){
//if true go to node
visited[vertex] = true;
list<int>::iterator i;
for(i = adjacent[vertex].begin(); i != adjacent[vertex].end(); ++i){
    if(!visited[*i]){
        fillIn(*i, visited, Stack);
    }
}
//gets all visited vertex and saves to stack
Stack.push(vertex);
}

//find SCC
void Graph::print(int node,int arr[]){
//storing
stack<int> Stack;

bool *visited = new bool[vertex2];

for(int i = 0; i < vertex2; i++){
    visited[i] = false;
}
    
//vertices goes to stack
for(int i = 0; i < vertex2; i++){
    if(visited[i] == false){
        fillIn(i, visited, Stack);
    }
}

//to reverse
Graph gr = getTranspose();

//looking for vertices that we didnt see
for(int i = 0; i < vertex2; i++){
    visited[i] = false;
}

//checking all vertices
while (Stack.empty() == false){
    //leave the stack
    int vertex = Stack.top();
    Stack.pop();
    if (visited[vertex] == false){
        gr.DFS(vertex, visited, vertex, arr);
        int min=vertex;
        for(int i = 0; i < node; i++){
            // check the vertex
            if(arr[i] == vertex){
                //check for min
                if(min > i){
                    min = i;
                }
            }
        }
    for(int i = 0; i < node; i++){
        if(arr[i] == vertex){
            arr[i] = min;
        }
    }
    }
}
}

int main(){

// declaring node and edges
int nodes;
int edges;
cin >> nodes;
cin >> edges;

Graph g(nodes);

// loop to access the edge
for(int i = 0; i < edges; i++){
    int u;
    int w;
    cin >> u >> w;
    g.addEdge(u,w);
}

int arr[nodes];
for(int i = 0; i < nodes; i++){
    arr[i] = nodes + 2;
}

g.print(nodes, arr);

//results
for(int i = 0; i < nodes; i++){
    cout << arr[i] << endl;
}
return 0;
}