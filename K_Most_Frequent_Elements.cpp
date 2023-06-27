#include <bits/stdc++.h> 
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    vector<int> ans;
    map<int,int> mp;
    for(auto x:arr){
        mp[x]++;
    }
    priority_queue<pair<int,int>> pq;
    for(auto x: mp){
        pq.push({x.second,x.first});
    }
    for (int i = 1; i <= k; i++) {
      ans.push_back(pq.top().second);
      pq.pop();
    }
    sort(ans.begin(),ans.end());
    return ans;
    // Write your code here.
}
