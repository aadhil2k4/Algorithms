#include<iostream>
#include<vector>
#include<limits.h>
#include<queue>

using namespace std;

vector<int> dijkstra(int V, vector<vector<int> >adj[], int S){
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    vector<int> dist(V, 1e9);
    dist[S] = 0;
    pq.push({0, S});
    while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto it : adj[node]){
            int edgeWeight = it[1];
            int adjNode = it[0];
            if(dis + edgeWeight < dist[adjNode]){
                dist[adjNode] = dis + edgeWeight;
                pq.push({dist[adjNode],adjNode});
            }
        }
    }
    return dist;
}

int main() {
    int V = 5; // Number of vertices
    int S = 0; // Source node

    // Create an adjacency list for the graph
    vector<vector<int> > adj[V];

    // Add edges (u, v, w) to the adjacency list
    adj[0].push_back({1, 2});  // edge from 0 to 1 with weight 2
    adj[0].push_back({4, 1});  // edge from 0 to 4 with weight 1
    adj[1].push_back({2, 3});  // edge from 1 to 2 with weight 3
    adj[4].push_back({2, 2});  // edge from 4 to 2 with weight 2
    adj[4].push_back({3, 1});  // edge from 4 to 3 with weight 1
    adj[3].push_back({2, 5});  // edge from 3 to 2 with weight 5

    vector<int> distances = dijkstra(V, adj, S);

    cout << "Shortest distances from source " << S << " are: \n";
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << " : " << distances[i] << "\n";
    }

    return 0;
}