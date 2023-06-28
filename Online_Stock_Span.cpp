#include <bits/stdc++.h> 
vector<int> findSpans(vector<int> &price) {
    int n=price.size();vector<int> ans;
    if(n==0) return ans;
    stack<pair<int,int>> vals;ans.push_back(1);vals.push({price[0],0});
    for(int i=1;i<n;i++){
        if(vals.empty()){
            ans.push_back(i+1);vals.push({price[i],i}); continue;
        }
        if(vals.top().first>price[i]){
            ans.push_back(1);vals.push({price[i],i});
        }
        else if(vals.top().first<=price[i]){
            while(!vals.empty() && vals.top().first<=price[i]){
                vals.pop();
            }
            if(vals.size()==0) ans.push_back(i+1);
            else ans.push_back(i-vals.top().second);
            vals.push({price[i],i});
        }
   }
//    for(auto x:ans){
//        cout<<x<<" ";
//    }
//    cout<<endl;
    return ans;
    // Write your code here.
}
