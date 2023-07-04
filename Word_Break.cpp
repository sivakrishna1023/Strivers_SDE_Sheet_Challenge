#include <bits/stdc++.h> 
bool solve(int i,set<string> s,vector<int>& dp,string target){
    if(i>=target.length()) return true;
    if(dp[i]!=-1){
        return dp[i];
    }
    string temp="";
    for(int j=i;j<target.length();j++){
         temp.push_back(target[j]);
         if(s.find(temp)!=s.end()){
             if(solve(j+1,s,dp,target)){
                dp[i]=true;
                return true;
             }
         }  
    }
    dp[i]=false;
    return false;
}
bool wordBreak(vector < string > & arr, int n, string & target) {
    set<string> load;
    int n1=target.length();
    for(int i=0;i<arr.size();i++){
        load.insert(arr[i]);
    }
    vector<int> dp(n1+1,-1);
    return solve(0,load,dp,target);
    // Write your code here.
}
