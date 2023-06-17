#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int mini=INT_MAX;int ans=0;
    for(int i=0;i<prices.size();i++){
        mini=min(mini,prices[i]);
        ans=max(ans,prices[i]-mini);
    }
    return ans;
    // Write your code here.
}
