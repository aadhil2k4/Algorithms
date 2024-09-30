#include <iostream>
#include<vector>
#include<queue>

using namespace std;

void bfs(vector<vector<int> >& adjList, int start, vector<bool>& visited){
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while(!q.empty()){
        int curr = q.front();
        cout << curr << " ";
        q.pop();
        for(auto& i: adjList[curr]){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

void addEdge(vector<vector<int> >& adjList, int u, int v){
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

    cout << "BFS Traversal: " << endl;

    bfs(adjList, 0 , visited);
}