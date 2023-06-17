#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	int miss=-1;
	int repeat;
	sort(arr.begin(),arr.end());
	for(int i=0;i<n-1;i++){
		if(arr[i]==arr[i+1]){
			repeat=arr[i];
		}
	   else if(arr[i]+1!=arr[i+1]){
			miss=arr[i]+1;
		}
	}
	if(miss==-1 && arr[0]==1){
		miss=arr[n-1]+1;
	}
    else if(arr[0]!=1){
		miss=1;
	}
	return {miss,repeat};
	// Write your code here 
	
}
