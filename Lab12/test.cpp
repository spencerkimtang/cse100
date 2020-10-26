#include <stdio.h>
#include <iostream>

using namespace std;

//Got help youtube "Tushar Roy" he provided coded examples and explained how the code should run, greeksforgreeks, textbook

//Still working on 4 out of 5 test case passed.

//weighted representation
//edge3 is where U points to V with the edge weight of W
struct edge3{
    int u;
    int v;
    int w;
};

//to show connected, directed and weighted
struct Graph{
    int vertex;
    int edge;
    //array of edges
    struct edge3 *edge2;
};

//based on textbook on page 651
void bellmanFord(struct Graph* graph, int src){
    int vertex = graph -> vertex;
    int edge = graph -> edge;   
    int dist[vertex];
    int parent[vertex]; //parent node
    int u;
    int v;
    int w;
    
    //initialize distance
    //distance of all vertices is infinity
    for (int i = 0; i < vertex; i++){
        dist[i] = INT_MAX;
        parent[i] = 0;
    }
    //source vertex 
    dist[src] = 0;

    //finds shortest distance (runs V - 1 times)
    //relax function based on page 649
    for (int i = 1; i <= vertex - 1; i++){
        for (int j = 0; j < edge; j++){
            u = graph -> edge2[j].u;
            v = graph -> edge2[j].v;
            w = graph -> edge2[j].w;
            if (dist[u] != INT_MAX && dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                parent[v] = u;
            }
        }
    }
    
    //checks for negatives by running relax on all edges 1 more time
    //if distance for any decrease, negative cycle return false
    for (int i = 0; i < edge; i++){
        u = graph -> edge2[i].u;
        v = graph -> edge2[i].v;
        w = graph -> edge2[i].w;
        if (dist[u] != INT_MAX && dist[v] > dist[u] + w){
            cout << "FALSE";
            return;
            }
        }

    //not a negative cycle
    cout << "TRUE" << endl;
    for (int i = 0; i < vertex; ++i){
        if (dist[i] == INT_MAX)
            cout << "INFINITY" << endl;
        else
            cout << dist[i] << endl;
    }
    
}

int main(){

int vertex; 
int edge;
  
cin >> vertex >> edge;
  
int u;
int v;
int w;

//use malloc since number of edges are different for each case
struct Graph *graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph -> vertex = vertex;
    graph -> edge = edge;
    //array of edges with the size of edge
    graph -> edge2 = (struct edge3*)malloc(graph -> edge *sizeof(struct edge3));

//stores vertex, edges, and weight
for(int i = 0; i < edge; i++){
    cin >> u >> v >> w;
    graph -> edge2[i].u = u;
    graph -> edge2[i].v = v;
    graph -> edge2[i].w = w;
}
  
bellmanFord(graph, 0);
return 0;
}