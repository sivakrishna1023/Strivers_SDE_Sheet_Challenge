#include<bits/stdc++.h>
int solve(int i1,int i2,string s1,string s2,vector<vector<int>>& dp){
	if(i1<0 || i2<0) return 0;
	if(dp[i1][i2]!=-1)
	return dp[i1][i2];
	if(s1[i1]==s2[i2]){
		return dp[i1][i2]=1+solve(i1-1,i2-1,s1,s2,dp);
	}
	if(s1[i1]!=s2[i2]){
		return dp[i1][i2]=max(solve(i1-1,i2,s1,s2,dp),solve(i1,i2-1,s1,s2,dp));
	}
}
int lcs(string s, string t)
{
	int n1=s.length(),n2=t.length();
	vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
	return solve(n1-1,n2-1,s,t,dp);
	//Write your code here
}
