#include<iostream>
#include<vector>

using namespace std;

void dfs(vector<vector<int> >& adjList,int start, vector<bool>& visited){
    visited[start] = true;
    cout << start << " ";
    for(auto& i: adjList[start]){
        if(!visited[i]){
            dfs(adjList, i, visited);
        }
    }
}

void addEdge(vector<vector<int> >& adjList, int u,int v){
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

int main(){
    int V = 5;
    vector<vector<int> > adjList(V);

    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 2, 4);

    vector<bool> visited(V, false);

    cout << "DFS Traversal: " << endl;

    dfs(adjList, 0, visited);
}