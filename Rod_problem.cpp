int solve(int i,int n,vector<int>& price,vector<vector<int>>& dp){
	if(n<=0 || i>=price.size()) return 0;
	//take case
	if(dp[i][n]!=-1) return dp[i][n];
	int take=0;
    if(n>i)  take=price[i]+solve(i,n-i-1,price,dp);
	//Not take case
	int nottake=solve(i+1,n,price,dp);
    // cout<<take<<" "<<nottake<<endl;
	return dp[i][n]=max(take,nottake);
}
int cutRod(vector<int> &price, int n)
{   int n1=price.size(); 
	vector<vector<int>> dp(n1,vector<int>(n+1,-1));
	return solve(0,n,price,dp);
	// Write your code here.
}
