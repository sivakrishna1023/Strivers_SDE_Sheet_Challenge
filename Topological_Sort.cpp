#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int> adj[v];
    vector<int> ins(v,0);
    for(int i=0;i<edges.size();i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        ins[edges[i][1]]++;
    }
    queue<int> q;
    for(int i=0;i<v;i++){
        if(ins[i]==0) q.push(i);
    }
    vector<int> vals;
    while(!q.empty()){
        int top=q.front();q.pop();
        vals.push_back(top);
        for(auto x:adj[top]){
            ins[x]--;
            if(ins[x]==0){
                q.push(x);
            }
        }

    }
    return vals;
    // Write your code here
}
