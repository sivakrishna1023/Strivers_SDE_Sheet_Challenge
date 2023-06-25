// #include<bits/stdc++.h>
// void solution(int i,int n,string& s,set<string>& vals){
//   if (i == n ) {
//     vals.insert(s);
//     return;
//   }
//   for(int index=i;index<=n;index++){
//       swap(s[i],s[index]);
//      // cout<<s<<endl;
//       solution(i+1,n,s,vals);
//       swap(s[i],s[index]);
//   }
// }
// string kthPermutation(int n, int k) {
//   string temp = "";
//   string s = "";
//   for (int i = 1; i <= n; i++)
//     s += char(i + '0');
//   set<string> vals;
//   solution(0, n - 1, s, vals);
//   vector<string> val(vals.begin(), vals.end());
//   return val[k - 1];
// }
string kthPermutation(int n, int k){
    string sol="";
    int fact=1;
    vector<int> ans;
    for(int i=1;i<n;i++){
        fact*=i; ans.push_back(i);
    }
    ans.push_back(n);k-=1;
    while(true){
        sol=sol+to_string(ans[k/fact]);
        ans.erase(ans.begin()+(k/fact));
        if(ans.size()==0){
            break;
        }
        k=k%fact;
        fact=fact/ans.size();
    }
    return sol;
    
}
