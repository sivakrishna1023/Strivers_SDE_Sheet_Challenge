#include <bits/stdc++.h> 
vector<int> merge(vector<int>& x,vector<int>& y){
    int i=0,j=0,n=x.size(),m=y.size();vector<int> temp;
    while(i<n && j<m){
        if(x[i]<=y[j]){
                temp.push_back(x[i++]);
        }
        else temp.push_back(y[j++]);
    }
    while(i<n) temp.push_back(x[i++]);
    while(j<m) temp.push_back(y[j++]);
    return temp;
}
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
     for(int i=kArrays.size()-1;i>0;i--){
         kArrays[i-1]=merge(kArrays[i-1],kArrays[i]);
     }   
     return kArrays[0];
    // Write your code here. 
}
