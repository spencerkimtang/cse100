// Declare the required header file

#include <iostream>

#include <list>

#include <stack>

// Define the namespace

using namespace std;

// create a class with the name of Strongly connected

// components

class Stronglyconnectedcomponent

{

// Declare the vertex

int Vertex;

// Declare a list od adjacent node

list<int> *adjacent;

// create a function to fill the node

void SCCfillID(int vertex, bool traveresd[], stack<int> &Stack);

// Create a function to use DFS approach to traverse

// the vertex node
void SSCDFS(int vertex, bool traveresd[],int node,int ar[]);
// create the bydefault constructor
public:
Stronglyconnectedcomponent(int Vertex);
void connectededge(int vertex, int w);
// create the function to print the the stongly connected
// components
void printSCCs(int node,int arr[]);
// get transpose method to conncet the graph
Stronglyconnectedcomponent getTranspose();
};

// define the function of strongly connected class
Stronglyconnectedcomponent::Stronglyconnectedcomponent(int Vertex)
{
// this method to traverse the vertex
this->Vertex = Vertex;
// traverse the adjacent vertex
adjacent = new list<int>[Vertex];
}


// Definene the Strongly connected to display the DFS tree vertex node
void Stronglyconnectedcomponent::SSCDFS(int vertex, bool traveresd[],int node,int arr[])
{
// which node is traversed, assign that is tru
traveresd[vertex] = true;
arr[vertex]=node;
// recall all the visted vertex in the list
list<int>::iterator i;
for (i = adjacent[vertex].begin(); i != adjacent[vertex].end(); ++i)
if (!traveresd[*i])
SSCDFS(*i, traveresd,node,arr);
}

Stronglyconnectedcomponent Stronglyconnectedcomponent::getTranspose()
{
Stronglyconnectedcomponent g(Vertex);
for (int vertex = 0; vertex < Vertex; vertex++)
{
// recall all the visited vertex in the list of that vertex
list<int>::iterator i;
for(i = adjacent[vertex].begin(); i != adjacent[vertex].end(); ++i)
{
g.adjacent[*i].push_back(vertex);
}
}
return g;
}


// to add the strongly connected componets
void Stronglyconnectedcomponent::connectededge(int vertex, int w)
{
adjacent[vertex].push_back(w); // Add w to v’s list.
}


// strongly connected components to fill the node
void Stronglyconnectedcomponent::SCCfillID(int vertex, bool traveresd[], stack<int> &Stack)
{
// visited node is true
traveresd[vertex] = true;
//// recall all the visited vertex in the list of that vertex
list<int>::iterator i;
for(i = adjacent[vertex].begin(); i != adjacent[vertex].end(); ++i)
if(!traveresd[*i])
SCCfillID(*i, traveresd, Stack);
// recall all the visited vertex in the list of that vertex
// and save into the stack
Stack.push(vertex);
}



// Create a function to display the finding strongly connected
// components
void Stronglyconnectedcomponent::printSCCs(int node,int arr[])
{
// to store the vertex into stack
stack<int> Stack;
//find and identify those vertices which is not visited
bool *traveresd = new bool[Vertex];
for(int i = 0; i < Vertex; i++)
traveresd[i] = false;
// vertices store into the stack.
for(int i = 0; i < Vertex; i++)
if(traveresd[i] == false)
SCCfillID(i, traveresd, Stack);
// reverse the strongly connected component graph
Stronglyconnectedcomponent gr = getTranspose();
// identify all the vertices which is not visited
for(int i = 0; i < Vertex; i++)
traveresd[i] = false;
// check all the vertices by order using while loop
while (Stack.empty() == false)
{
// exit the vertx from the stack
int vertex = Stack.top();
Stack.pop();
// check the exit vertex
if (traveresd[vertex] == false)
{
gr.SSCDFS(vertex, traveresd,vertex,arr);
int min=vertex;
for(int i=0;i<node;i++)
{
// check the vertex
if(arr[i]==vertex)
{
// check the minimum vertex
if(min>i)
min=i;
}
}
// loop to access the node
for(int i=0;i<node;i++)
if(arr[i]==vertex)
arr[i]=min;
//cout << endl;
}
}
}
// create a main function of the program
int main()
{
// declare required variable for input node and vertex
int node,edge;
cin>>node;
cin>>edge;
// call the function
Stronglyconnectedcomponent g(node);
// loop to access the edge
for(int i=0;i<edge;i++)
{
// vertex u and w
int u,w;
cin>>u>>w;
g.connectededge(u,w);
}
int arr[node];
for(int i=0;i<node;i++)
{
arr[i]=node+2;
}
g.printSCCs(node,arr);
// Display the result
//cout << "Output for problem:"<<endl;
for(int i=0;i<node;i++)
{
cout<<arr[i]<<endl;
}
return 0;
}