#include <bits/stdc++.h> 
string writeAsYouSpeak(int n) 
{
	string ans="1";
	if(n==1) return ans;
	else if(n==2) return "11";
	ans="11";
	for(int i=3;i<=n;i++){
		string temp="";char c=ans[0];int cnt=1;
		for(int i=1;i<ans.length();i++){
				if(c==ans[i]){
					cnt++;
				}else{
					//cout<<temp<<" "<<to_string(cnt)<<" "<<c<<endl;
					temp=temp+to_string(cnt)+c;
					c=ans[i];cnt=1;
				}
		    }
		    temp=temp+to_string(cnt)+c;
				c=ans[i];cnt=1;
				 ans=temp;
			}
		 
		  return ans;
}	
	// Write your code here.	
