#include<bits/stdc++.h>

int getAns(int arr[], int n,  int ind, int prev_index, vector<vector<int>>& dp){
    
    // base condition
    if(ind == n)
        return 0;
        
    if(dp[ind][prev_index+1]!=-1)
        return dp[ind][prev_index+1];
    
    int notTake = 0 + getAns(arr,n,ind+1,prev_index,dp);
    
    int take = 0;
    
    if(prev_index == -1 || arr[ind] > arr[prev_index]){
        take = 1 + getAns(arr,n,ind+1,ind,dp);
    }
    
    return dp[ind][prev_index+1] = max(notTake,take);
}
int solve(int i,int prev,int arr[],int n,vector<vector<int>>&dp){
    if(i==n) return 0;
   
    if(dp[i][prev+1]!=-1) 
    return dp[i][prev+1];

    int nottake=solve(i+1,prev,arr,n,dp);

    int take=0;
    
    if(prev==-1 || arr[i]>arr[prev]){
        take=1+solve(i+1,i,arr,n,dp);
    }
   
    return dp[i][prev+1]=max(take,nottake);
}
int solution(int arr[],int n){
    if(n==0) return 0;
    vector<int> ans;
    ans.push_back(arr[0]);
    for(int i=1;i<n;i++){
        if(arr[i]>ans.back()){
            ans.push_back(arr[i]);
        }else{
            int index=lower_bound(ans.begin(),ans.end(),arr[i])-ans.begin();
            ans[index]=arr[i];
        }
    }
    return ans.size();
}
int longestIncreasingSubsequence(int arr[], int n)
{
    return solution(arr,n);
    //vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    // return solve(0,-1,arr,n,dp);
    // return getAns(arr,  n,0,-1, dp);
    // Write Your Code here
}
