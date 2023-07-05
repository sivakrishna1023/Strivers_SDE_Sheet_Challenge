int solve(int i,int j,string s1,string s2,vector<vector<int>> &dp){

     if(i<0) return j+1;
     if(j<0) return i+1;
     if(dp[i][j]!=-1) return dp[i][j]; 
     if(s1[i]==s2[j]){
          return  dp[i][j]=solve(i-1,j-1,s1,s2,dp);
     }
     else{
         return dp[i][j]=1+min(solve(i-1,j-1,s1,s2,dp),min(solve(i,j-1,s1,s2,dp),solve(i-1,j,s1,s2,dp)));
     }
}
int editDistanceUtil(string& S1, string& S2, int i, int j, vector<vector<int>>& dp){
    
    if(i<0)
        return j+1;
    if(j<0)
        return i+1;
        
    if(dp[i][j]!=-1) return dp[i][j];
        
    if(S1[i]==S2[j])
        return dp[i][j] =  0+editDistanceUtil(S1,S2,i-1,j-1,dp);
        
    // Minimum of three choices
    else return dp[i][j] = 1+min(editDistanceUtil(S1,S2,i-1,j-1,dp),
    min(editDistanceUtil(S1,S2,i-1,j,dp),editDistanceUtil(S1,S2,i,j-1,dp)));
    
}
int editDistance(string str1, string str2)
{
    int n1=str1.length(),n2=str2.length();
    vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
    for(int i=0;i<=n1;i++){
        for(int j=0;j<=n2;j++){
            if(i==0) dp[i][j]=j;
            else if(j==0) dp[i][j]=i;
            else if(str1[i-1]==str2[j-1]) dp[i][j]=dp[i-1][j-1];
            else{
                dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
            }
        }
    }
    return dp[n1][n2];
   //return solve(n1-1,n2-1,str1,str2,dp);
  // return editDistanceUtil(str1,str2,n1-1,n2-1,dp);
    //write you code here
}
