#include <bits/stdc++.h> 
#include<vector>
// void minHeapify(int i,vector<int>&myheap){
//     int lchild=2*i+1;
//     int rchild=2*i+2;
//     int smallest=i;
//     if(myheap[lchild]<myheap[i] && lchild<myheap.size()){
//         smallest=lchild;
//     }
//     if(myheap[rchild]<myheap[i] && myheap[rchild]<myheap[lchild] && rchild<myheap.size()){
//         smallest=rchild;
//     }
//     if(smallest!=i){
//         swap(myheap[smallest],myheap[i]);
//         minHeapify(smallest,myheap);
//     }
//     return;
// }
void minHeapify(int i,vector<int>& a){
    int left=2*i+1;
    int right=2*i+2;
    int smallest=i;
    if(left<a.size() && a[left]<a[i]){
        smallest=left;
    }
    if(right<a.size() && a[right]<a[i] && a[right]<a[left]){
        smallest=right;
    }
    if(smallest!=i){
        swap(a[i],a[smallest]);
        minHeapify(smallest,a);
    }
    return;
}
void insert(vector<int>& nums,int val){
      nums.push_back(val);
      int n=nums.size()-1;
      int par=(n-1)/2;
      while(nums[par]>nums[n]){
          minHeapify(par,nums);
          n=par;
          par=(par-1)/2;
      }
     
}
int del(vector<int>& nums){
    if(nums.size()==0) return -1;
    int val=nums[0];
   swap(nums[0],nums[nums.size()-1]);
   nums.pop_back();
   minHeapify(0,nums);
   return val;
}
// cout<<endl;
vector<int> minHeap(int n, vector<vector<int>>& q) {
    // vector<int> vals={8, 90, 9, 99,7};
    //     for(int i=vals.size()/2;i>=0;i--){
    //         minHeapify(i,vals);
    //     }
    //     for(auto x:vals){
    //         cout<<x<<" ";
    //     }
    vector<int> ans;
    vector<int> vals;
    for(auto x:q){
        if(x[0]==0){
            insert(vals,x[1]);
        }
        else if(x[0]==1){
            ans.push_back(del(vals));
        }
    }
    return ans;
    // Write your code here.
}
