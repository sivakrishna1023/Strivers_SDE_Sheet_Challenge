#include <bits/stdc++.h> 
class disjointset{
   public:
     vector<int> rank,parents,size;
     disjointset(int n){
        rank.resize(n+1,0);
        parents.resize(n+1,0);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parents[i]=i;
            //size[i]=1;
        }
     }
     int findparent(int node){
        if(node==parents[node]) return node;
        return parents[node]=findparent(parents[node]);
     }
     void unionrank(int u,int v){
        int ult_u=findparent(u);
        int ult_v=findparent(v);
        if(ult_u==ult_v) return;
        else if(rank[ult_u]<rank[ult_v]) parents[ult_u]=ult_v;
        else if(rank[ult_v]<rank[ult_u]) parents[ult_v]=ult_u;
        else{
            parents[ult_v]=ult_u;
            rank[ult_u]++;
        }
     }
     void unionsize(int u,int v){
        int ult_u=findparent(u);
        int ult_v=findparent(v);
        if(ult_v==ult_u) return;
        else if(size[ult_v]<size[ult_u]){
            parents[ult_v]=ult_u;size[ult_u]+=size[ult_v];
        }
        else{
            parents[ult_u]=ult_v;size[ult_v]+=size[ult_u];
        }
     }
};
int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	vector<pair<int,int>> adj[n+1];
	for(auto x:graph){
		adj[x[0]].push_back({x[1],x[2]});
		adj[x[1]].push_back({x[0],x[2]});
	}
	vector<pair<int,pair<int,int>>> vals;
	for(int i=1;i<n+1;i++){
		for(auto x:adj[i]){
			int node=x.first,wt=x.second;
			vals.push_back({wt,{i,node}});
		}
	}
	disjointset dis(n+1);
	sort(vals.begin(),vals.end());int ans=0;
	for(auto x:vals){
		int wt=x.first;
		int u=x.second.first;
		int v=x.second.second;
		if(dis.findparent(u)!=dis.findparent(v)){
				ans+=wt;
				dis.unionrank(u,v);
		}
	}
	return ans;
	// Write your code here.
}
