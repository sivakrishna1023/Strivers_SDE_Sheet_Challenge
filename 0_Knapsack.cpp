#include<bits/stdc++.h>
int solve(int index,int w,vector<int>& nums,vector<int>&weights,vector<vector<int>>& dp){
    if(index==0){
        if(w>=weights[index]) return nums[0];
        else return 0;
    }
    if(dp[index][w]!=-1)
    return dp[index][w];
    //take case
    int take=INT_MIN;
    if(weights[index]<=w) take=nums[index]+solve(index-1,w-weights[index],nums,weights,dp);
    //nottake case
    int nottake=solve(index-1,w,nums,weights,dp);
    return dp[index][w]=max(take,nottake);
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    vector<vector<int>> dp(n+1,vector<int>(w+1,-1));
    return solve(n-1,w,values,weights,dp);
	// Write your code here
}
