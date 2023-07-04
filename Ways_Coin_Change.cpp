#include<bits/stdc++.h>
long long  solve(int i,int value,int *nums,int n,vector<vector<long long>>&dp){
    if(value<0 || i>=n) return 0;
    if(value==0) return 1;
    //take case
    if(dp[i][value]!=-1) return dp[i][value];
    long take=0;
    take=solve(i,value-nums[i],nums,n,dp);
    //Not take case
    long nottake=solve(i+1,value,nums,n,dp);
    return  dp[i][value]=take+nottake;
}
long countWaysToMakeChange(int *denominations, int n, int value)
{  
    vector<vector<long long>> dp(n+1,vector<long long>(value+1,-1)); 
    return solve(0,value,denominations,n,dp);
    //Write your code here
}
