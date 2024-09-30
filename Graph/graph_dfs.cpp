#include<iostream>
#include<vector>

using namespace std;

void dfs(vector<vector<int> >& adjMatrix, int start, vector<bool>& visited){
    visited[start] = true;
    cout << start << " ";
    for(int i=0; i<adjMatrix.size(); i++){
        if(adjMatrix[start][i] == 1 && !visited[i]){
            dfs(adjMatrix, i, visited);
        }   
    }
}

void addEdge(vector<vector<int> >& adjMatrix, int u, int v){
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;
}

int main(){
    int V = 5;
    vector<vector<int> > adjMatrix(V, vector<int>(V, 0));

    addEdge(adjMatrix, 0, 1);
    addEdge(adjMatrix, 0, 2);
    addEdge(adjMatrix, 1, 3);
    addEdge(adjMatrix, 1, 4);
    addEdge(adjMatrix, 2, 4);

    vector<bool> visited(V, false);

    cout << "DFS Traversal: " << endl;

    dfs(adjMatrix, 0, visited);
}