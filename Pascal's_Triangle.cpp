#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n) 
{
  vector<vector<long long int>> ans;
  for(int i=1;i<=n;i++){
    vector<long long int> vals;
    if(i==1){
      vals.push_back(1);ans.push_back(vals);continue;
    }
    else if(i==2){
      vals.push_back(1);vals.push_back(1);ans.push_back(vals);continue;
    }
    else{
      vals.resize(i);
      // vals[1]=ans[i-2][0]+ans[i-2][1];
      // cout<<vals[1]<<endl;
      for(int j=0;j<i;j++){
        if(j==0 || j==i-1) vals[j]=1;
        else{
          vals[j]=ans[i-2][j-1]+ans[i-2][j];
        }
      }
      ans.push_back(vals);
    }
  }
  return ans;
  // Write your code here.
}
