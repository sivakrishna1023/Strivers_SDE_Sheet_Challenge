#include <bits/stdc++.h> 
int solve(int i,int prev,vector<int>& nums,int n,vector<vector<int>>&dp){
	if(i==n){
	  return 0;
	}
	if(dp[i][prev+1]!=-1) return dp[i][prev+1];
	int nottake=solve(i+1,prev,nums,n,dp);
	int take=0;
	if(prev==-1 || nums[i]>nums[prev]){
		take=nums[i]+solve(i+1,i,nums,n,dp);
	}
	return dp[i][prev+1]=max(take,nottake);
}
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
	return solve(0,-1,rack,n,dp);
	// Write your code here
}
