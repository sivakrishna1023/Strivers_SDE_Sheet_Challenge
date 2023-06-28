vector<int> stringMatch(string text, string pattern) {
	int j=0,i=0,prev=0;vector<int> ans;
	while(i<text.size()){
		if(j<pattern.size() && text[i]==pattern[j]){
			j++;
		}
		else if(j==pattern.size()){
			ans.push_back(i-j+1);i=prev;j=0;prev++;
		}
		else{
			j=0;i=prev;prev++;
		}i++;
	}
	if(j==pattern.size()) ans.push_back(i-j+1);
	return ans;
	// Write your code here.
}
