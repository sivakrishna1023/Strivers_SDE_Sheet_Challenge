#include <bits/stdc++.h> 
bool solve(int i,int k,vector<int>& arr,vector<vector<int>>& dp){
    if(i==0){
        if(arr[0]==k) return true;
        else if(k==0) return true;
        else return false;
    }
    if(dp[i][k]!=-1) return dp[i][k];
    //take case
    bool take= false;
    if(arr[i]<=k) take=solve(i-1,k-arr[i],arr,dp);
    //not take case
    bool nottake=solve(i-1,k,arr,dp);
    if(take || nottake){
        dp[i][k]=1;
    }else{
        dp[i][k]=0;
    }
    return dp[i][k];
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    sort(arr.begin(),arr.end());
    vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
    return solve(n-1,k,arr,dp);
    // Write your code here.
}
