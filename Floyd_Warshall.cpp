int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<vector<long long >> vals(n+1,vector<long long>(n+1,1e9));
    for(auto x:edges){
        long long u=x[0],v=x[1],wt=x[2];
        vals[u][v]=wt;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
              vals[i][j]=0;
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                vals[i][j]=min(vals[i][j],vals[i][k]+vals[k][j]);
            }
        }
    }
    //1000000000
    if(vals[src][dest]>=1e8) return 1000000000;
    else return vals[src][dest];
    // Write your code here.
}
