#include<iostream>
#include<queue>
#include<vector>
using namespace std;

bool hasCycle(int curr, vector<int> adj[], vector<int> &vis){
    queue<pair<int,int>> q;
    q.push({curr, -1});

    while(!q.empty()){
        int node = q.front().first;
        int prev = q.front().second;
        q.pop();

        for(auto it: adj[node]){
            if(vis[it] == 0){
                vis[it] = 1;
                q.push({it, node});
            }else if(prev != it){
                return true;
            }
        }
    }
return false;
}

bool isCycle(int n, vector<int> adj[]){
    vector<int> vis(n+1, 0);
    for(int i=1; i<=n; i++){
        if(vis[i]==0){
            if(hasCycle(i, adj, vis)){
                return true;
            }
        }
    }
return false;
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

    bool graphHasCycle = isCycle(n, adj);

    cout<<graphHasCycle<<endl;
return 0;
}