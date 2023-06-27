#include <bits/stdc++.h> 
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    priority_queue<pair<int,int>> q;
    for(int i=0;i<k;i++){
        q.push({nums[i],i});
    }
    vector<int> ans;
    ans.push_back(q.top().first);
    for(int i=k;i<nums.size();i++){
           q.push({nums[i],i});
           while(q.top().second<=i-k){
               q.pop();
           }
           ans.push_back(q.top().first);
      
    }
    return ans;
    //    Write your code here.
}
