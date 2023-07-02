bool dfs(int node,int col,vector<int> adj[],vector<int>& color){
        color[node]=col;
		for(auto x:adj[node]){
			if(color[x]==-1){
				if(!dfs(x,!col,adj,color)) return false;
			}
			else if(color[x]==col) return false;
		}
		return true;

}
bool isGraphBirpatite(vector<vector<int>> &edges) {
	int n=edges.size();
	vector<int> adj[n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(edges[i][j]==1){
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}
    vector<int> color(n,-1);
	for(int i=0;i<n;i++){
		if(color[i]==-1){
			if(!dfs(i,0,adj,color)) return false;
 		}
	}
	return true;
	// Write your code here.
}
