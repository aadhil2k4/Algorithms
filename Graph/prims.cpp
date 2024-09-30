#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int prims(int V, vector<vector<pair<int, int> > > &adj) {
    // Min-heap to store {weight, node}
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    vector<int> vis(V, 0);  // To track visited nodes
    pq.push({0, 0});  // Start from node 0 with weight 0
    int sum = 0;  // Sum of weights of MST

    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first;
        
        if (vis[node] == 1) {
            continue;
        }
        
        // Add to MST
        vis[node] = 1;
        sum += wt;

        // Traverse adjacent nodes
        for (auto &it : adj[node]) {
            int adjNode = it.first;
            int edWt = it.second;
            if (!vis[adjNode]) {
                pq.push({edWt, adjNode});
            }
        }
    }
    return sum;
}

int main() {
    int V = 5;  // Number of vertices
    int E = 6;  // Number of edges

    vector<vector<pair<int, int> > > adj(V);  // Adjacency list

    // Edges and their weights
    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});

    adj[0].push_back({3, 6});
    adj[3].push_back({0, 6});

    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});

    adj[1].push_back({3, 8});
    adj[3].push_back({1, 8});

    adj[1].push_back({4, 5});
    adj[4].push_back({1, 5});

    adj[2].push_back({4, 7});
    adj[4].push_back({2, 7});

    // Calculate the MST weight using Prim's algorithm
    int mstWeight = prims(V, adj);
    cout << "The weight of the Minimum Spanning Tree is: " << mstWeight << endl;

    return 0;
}

