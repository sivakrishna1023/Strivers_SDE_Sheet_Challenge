#include <bits/stdc++.h> 
vector<int> dijkstra(vector<vector<int>> &edges, int vertices, int edges1, int source) {
    vector<pair<int,int>> adj[vertices];
    for(int i=0;i<edges.size();i++){
        adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
    }
    vector<int> dis(vertices,1e18);
    dis[source]=0;
    queue<pair<int,int>> q;
    q.push({0,0});
    while(!q.empty()){
        auto p=q.front();q.pop();
        int node=p.first;int len=p.second;
        for(auto x:adj[node]){
            int node1=x.first,edglen=x.second;
            if(len+edglen<dis[node1]){
                dis[node1]=len+edglen;
                q.push({node1,len+edglen});
            }
        }
    }
    return dis;
    // Write your code here.
}
