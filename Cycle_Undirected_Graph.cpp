#include<bits/stdc++.h>
// bool bfs(int node,vector<int> adj[],vector<bool>& vis){
//     queue<int> q;
//     q.push(node);
//     while(!q.empty()){
//         int node1=q.front();q.pop();
//         vis[node1]=true;
//         for(auto x:adj[node1]){
//             if(vis[x]==true && x!=node1) return true;
//             q.push(x);
//         }
//     }
//     return false;
// }
bool iscycle(int node,int parent,vector<int> adj[],vector<bool>& vis){
    vis[node]=true;
    for(auto x: adj[node]){
       if(!vis[x]){
            if(iscycle(x,node,adj,vis)) return true;
       }
       else if(x!=parent) return true;
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<int> adj[n+1];
    for(int i=0;i<edges.size();i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    // vector<bool> vis(n+1,false);
    //     vis[0]=true;
    vector<bool> vis(n+1,false);
    vis[0]=true;
    for(int i=1;i<n+1;i++){
        if(!vis[i]){
             if(iscycle(i,i,adj,vis)) return "Yes";
        }
    }
    return "No";
    // Write your code here.
}
