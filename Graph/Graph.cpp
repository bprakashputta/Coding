#include<iostream>
#include<vector>
using namespace std;

void naiveGraphImplementation(){
    int n,m;
    cin>>n>>m;
    cout<<"################"<<endl;
    int adj[n+1][n+1] = {};
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"################"<<endl;
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    cout<<"################"<<endl;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"################"<<endl;
    // cout<<"Ji"<<endl;
}

void naiveWeightedGraphImplementation(){
    int n,m;
    cin>>n>>m;
    int adj[n+1][n+1][2] = {};
    cout<<"################"<<endl;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            cout<<adj[i][j][0]<<" ";
        }
        cout<<endl;
    }
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            cout<<adj[i][j][1]<<" ";
        }
        cout<<endl;
    }    cout<<"################"<<endl;
    for(int i=0; i<m; i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u][v][0] = 1;
        adj[u][v][1] = w;
        adj[v][u][0] = 1;
        adj[v][u][1] = w;
    }
    cout<<"################"<<endl;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            cout<<adj[i][j][0]<<" ";
        }
        cout<<endl;
    }
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            cout<<adj[i][j][1]<<" ";
        }
        cout<<endl;
    }
    cout<<"################"<<endl;
}

void adjacencyListGraphImplementation(){
    int n,m;
    cin>>n>>m;
    cout<<"################"<<endl;
    // int adj[n+1][n+1] = {};
    // instead of an array here
    // we will declare an array of vector
    vector<int> adj[n+1];

    for(int i=0; i<=n; i++){
        for(int j=0; j<adj[i].size(); j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"################"<<endl;
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        // adj[u][v] = 1;
        // adj[v][u] = 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<"################"<<endl;
    for(int i=0; i<=n; i++){
        for(int j=0; j<adj[i].size(); j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"################"<<endl;
    // cout<<"Ji"<<endl;
}

void weightedAdjacencyListGraphImplementation(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> adj[n+1];
    cout<<"################"<<endl;
    for(int i=0; i<=n; i++){
        for(int j=0; j<adj[i].size(); j++){
            cout<<adj[i][j].first<<" ";
        }
        cout<<endl;
    }
    for(int i=0; i<=n; i++){
        for(int j=0; j<adj[i].size(); j++){
            cout<<adj[i][j].second<<" ";
        }
        cout<<endl;
    }
    cout<<"################"<<endl;    
    for(int i=0; i<m; i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    cout<<"################"<<endl;
    for(int i=0; i<=n; i++){
        for(int j=0; j<adj[i].size(); j++){
            cout<<adj[i][j].first<<" ";
        }
        cout<<endl;
    }
    for(int i=0; i<=n; i++){
        for(int j=0; j<adj[i].size(); j++){
            cout<<adj[i][j].second<<" ";
        }
        cout<<endl;
    }
    cout<<"################"<<endl;
}

int main(){
    // naiveGraphImplementation();
    // naiveWeightedGraphImplementation();
    // adjacencyListGraphImplementation();
    weightedAdjacencyListGraphImplementation();

return 0;
}