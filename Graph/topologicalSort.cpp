#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void dfs(int node, vector<int>& vis, stack<int>&st, vector<int> adj[]){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it, vis, st, adj);
        }
    }
    st.push(node);
}

vector<int> topologicalSort(int V, vector<int>adj[]){
    vector<int> vis(V, 0); 
    stack<int> st;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            dfs(i, vis, st, adj);
        }
    }
    vector<int> ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main() {
    int V = 6;  
    vector<int> adj[V];

    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    vector<int> result = topologicalSort(V, adj);

    cout << "Topological Sort: ";
    for (auto it : result) {
        cout << it << " ";
    }

    return 0;
}