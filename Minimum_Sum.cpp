#include <bits/stdc++.h> 
int minSumPath(vector<vector<int>> &grid) {
     int n=grid.size(),m=grid[0].size();
     vector<vector<int>> dp(n+1,vector<int>(m+1,1e9));
     dp[1][1]=grid[0][0];
     for(int i=1;i<=n;i++){
         for(int j=1;j<=m;j++){
            if(i==j && i==1) continue;
            dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i-1][j-1];
         }
     }
    //  for(int i=1;i<=n;i++){
    //      for(int j=1;j<=m;j++){
    //          cout<<dp[i][j]<<" ";
    //      }
    //      cout<<endl;
    //  }
     return dp[n][m];
    // Write your code here.
}
