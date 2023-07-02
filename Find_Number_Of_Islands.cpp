void dfs(int x,int y,int** arr,vector<vector<int>>& vals,int n,int m){
     vals[x][y]=1;
     int dx[]={1,-1,0,0,1,-1,1,-1};
     int dy[]={0,0,1,-1,-1,-1,1,1};
     for(int i=0;i<8;i++){
         int x1=x+dx[i];
         int y1=y+dy[i];
         if(x1>=0 && y1>=0 && x1<n && y1<m && arr[x1][y1]==1 && !vals[x1][y1]){
            dfs(x1,y1,arr,vals,n,m);
         }
     }
}
int getTotalIslands(int** arr, int n, int m)
{  vector<vector<int>> vals(n,vector<int>(m,0));int ans=0;
   for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
         if(arr[i][j]==1 && !vals[i][j]){
            ans++;
           // cout<<i<<" "<<j<<endl;
            dfs(i,j,arr,vals,n,m);
         }
      }
   }
   return ans;
   // Write your code here.
}
