#include<bits/stdc++.h>
string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans=arr[0];
    for(int i=1;i<n;i++){
        string temp=arr[i];int j=0;
        while(j<ans.length() && j<temp.length() && temp[j]==ans[j]){
                j++;
        }
        while(ans.size()>j) ans.pop_back();
    }
    return ans;
    // Write your code here
}
