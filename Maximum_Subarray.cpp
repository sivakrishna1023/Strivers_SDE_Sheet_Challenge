#include <bits/stdc++.h> 

int maximumProduct(vector<int> &arr, int n)
{
	
	int maxi=INT_MIN,pre=1,suff=1;
	for(int i=0;i<n;i++){
		if(pre==0) pre=1;
		if(suff==0) suff=1;
		pre*=arr[i];
		suff*=arr[n-i-1];
		maxi=max(maxi,max(pre,suff));
	}
	return maxi;
	// Write your code here
}
