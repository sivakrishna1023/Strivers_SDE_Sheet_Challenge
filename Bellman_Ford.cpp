#include <bits/stdc++.h> 
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<int> dis(n+1,1e9);
    dis[src]=0;
    for(int i=0;i<n-1;i++){
            for(auto x:edges){
                int u=x[0],v=x[1],wt=x[2];
                if(dis[u]!=1e9 && dis[u]+wt<dis[v]){
                    dis[v]=dis[u]+wt;
                }
            }
    }
    return dis[dest];
    // Write your code here.
}
