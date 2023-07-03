#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int,list<pair<int,int>>> adj;
    for(auto x:g){
        int u=x.first.first,v=x.first.second,wt=x.second;
        adj[u].push_back(make_pair(v,wt));
        adj[v].push_back(make_pair(u,wt));
    }
    vector<int> key(n+1);
    vector<bool>mst(n+1);
    vector<int> parent(n+1);
    for(int i=0;i<=n;i++){
        key[i]=INT_MAX;
        parent[i]=-1;
        mst[i]=false;
    }
    key[1]=0;
    parent[1]=-1;
    for(int i=1;i<n;i++){
        int mini=INT_MAX,u;
        for(int v=1;v<=n;v++){
            if(mst[v]==false && key[v]<mini){
                u=v;
                mini=key[v];
            }
        }
        mst[u]=true;
        for(auto x:adj[u]){
            int v=x.first,wt=x.second;
            if(mst[v]==false && wt<key[v]){
                parent[v]=u;
                key[v]=wt;
            }
        }
    }
    vector<pair<pair<int,int>,int>> ans;

    for(int i=2;i<=n;i++){
        ans.push_back({{parent[i],i},key[i]});
    }
    return ans;
    // Write your code here.
}
