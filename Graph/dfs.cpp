#include<iostream>
#include<vector>
using namespace std;

void solve(int node, vector<int> adj[], vector<int> &vis, vector<int> &dfs){
    dfs.push_back(node);
    vis[node] = 1;
    for(auto it: adj[node]){
        if(vis[it]==0){
            solve(it, adj, vis, dfs);
        }
    }
}

vector<int> dfsOfGraph(int n, vector<int> adj[]){
    vector<int> dfs;
    vector<int> vis(n+1,0);
    for(int i=1; i<=n; i++){
        if(vis[i]==0){
            solve(i, adj, vis, dfs);
        }
    }
return dfs;
}

int main(){
    int n,m;
    cin>>n>>m;
    
    vector<int> adj[n+1];
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dfs = dfsOfGraph(n, adj);

    for(int i=0; i< dfs.size(); i++){
        cout<<dfs[i]<<" ";
    }
    cout<<endl;
return 0;
}