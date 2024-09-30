#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void bfs(vector<vector<int> >& adjMatrix, int start, vector<bool>& visited){
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while(!q.empty()){
        int curr = q.front();
        cout << curr << " ";
        q.pop();
        for(int i=0; i<adjMatrix.size(); i++){
            if(adjMatrix[curr][i]==1 && !visited[i]){
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

void addEdge(vector<vector<int> >& adjMatrix, int u, int v){
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;
}

int main(){
    int V =5; 

    vector<vector<int> > adjMatrix(V, vector<int>(V, 0));
    
    addEdge(adjMatrix, 0, 1);
    addEdge(adjMatrix, 0, 2);
    addEdge(adjMatrix, 1, 3);
    addEdge(adjMatrix, 1, 4);
    addEdge(adjMatrix, 2, 4);

    vector<bool> visited(V, false);

    cout << "BFS Traversal: " << endl;

    bfs(adjMatrix, 0, visited);
}

