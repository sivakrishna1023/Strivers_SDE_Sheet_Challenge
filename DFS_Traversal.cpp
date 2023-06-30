void dfs(int node,vector<int> adj[],vector<bool>& vis,vector<int>&temp){
    vis[node]=true;
    temp.push_back(node);
    for(auto x:adj[node]){
        if(!vis[x]){
             dfs(x,adj,vis,temp);
        }
    }
    return;
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{   vector<vector<int>> ans;
    vector<int> adj[V];
    for(auto x:edges){
        adj[x[1]].push_back(x[0]);
        adj[x[0]].push_back(x[1]);
    }
    vector<bool> vis(V,false);
    for(int i=0;i<V;i++){
        if(!vis[i]){
            vector<int> temp;
            dfs(i,adj,vis,temp);
            ans.push_back(temp);
        }
    }
    return ans;
    // Write your code here
}
