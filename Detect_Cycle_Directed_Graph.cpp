#include<bits/stdc++.h>
bool bfs(int node,vector<int> adj[],vector<bool>& vis){
  queue<int> q;
  q.push(node);
  while(!q.empty()){
    int node1=q.front();q.pop();
    vis[node1]=true;
    for(auto x:adj[node1]){
      if(vis[x]==true && x!=node1) return true;
      q.push(x);
    }
  }
  return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  vector<int> adj[n+1];
  for(int i=0;i<edges.size();i++){
    adj[edges[i].first].push_back(edges[i].second);
  }
  vector<bool> vis(n+1,false);
  vis[0]=true;
  for(int i=1;i<n+1;i++){
     vector<bool> vis(n+1,false);
     vis[0]=true;
      if(!vis[i]){
        if(bfs(i,adj,vis)) return 1;
      }
  }
  return 0;
  // Write your code here.
}
