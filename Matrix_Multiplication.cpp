#include <bits/stdc++.h> 
int solve(int i,int j,vector<int>& arr, vector<vector<int>>& dp){
    if(i==j) return 0;
    int mini=INT_MAX;
    if(dp[i][j]!=-1) return dp[i][j];
    for(int k=i;k<j;k++){
        int ans=arr[j]*arr[k]*arr[i-1]+solve(i,k,arr,dp)+solve(k+1,j,arr,dp);
        mini=min(ans,mini);
    }
    return dp[i][j]=mini;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N,vector<int>(N,-1));
    return solve(1,N-1,arr,dp);
    // Write your code here.
}
