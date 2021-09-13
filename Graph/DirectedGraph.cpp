#include<iostream>
#include<vector>
using namespace std;

// 1 2
// 2 4
// 2 3
// 3 5
// 4 1

void naiveDirectedGraphImplementation(){
    int n,m;
    cin>>n>>m;
    int adj[n+1][n+1]={};
    cout<<"#################"<<endl;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"#################"<<endl;
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u][v] = 1;
    }
    cout<<"#################"<<endl;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"#################"<<endl;
}

void naivedirectedWeightedGraphImplementation(){
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
        // this is true only for undirected graph
        // adj[v][u][0] = 1;
        // adj[v][u][1] = w;
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

void directedAdjacencyListImplementataion(){
    int n, m;
    cin>>n>>m;
    vector<int> adj[n+1];
    cout<<"#################"<<endl;
    for(int i=0; i<=n; i++){
        for(int j=0; j<adj[i].size(); j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"#################"<<endl;
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    cout<<"#################"<<endl;
    for(int i=0; i<=n; i++){
        for(int j=0; j<adj[i].size(); j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"#################"<<endl;
}

void directedWeightedAdjacencyListGraphImplementation(){
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
        // this is true only for undirected graph
        // adj[v].push_back({u,w});
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
    // naiveDirectedGraphImplementation();
    // naivedirectedWeightedGraphImplementation();
    // directedAdjacencyListImplementataion();
    directedWeightedAdjacencyListGraphImplementation();
return 0;
}