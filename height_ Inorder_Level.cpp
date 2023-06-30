#include <bits/stdc++.h> 

struct Node{
	int height;
	int leftindex;
	int rightindex;
};
int heightOfTheTree(vector<int>& inorder, vector<int>& levelOrder, int N){
	queue<Node>q;
	Node newnode;
	newnode.height=0;
	newnode.leftindex=0;
	newnode.rightindex=N-1;
	q.push(newnode);
	int ans=0;
	map<int,int> mp;
	for(int i=0;i<N;i++) mp[inorder[i]]=i;
	
	for(int i=0;i<N;i++){
		int curr=levelOrder[i];
		Node now=q.front();q.pop();
		int curpos=mp[levelOrder[i]];
		if(curpos>now.leftindex){
			Node newnode1;
			newnode1.height=now.height+1;
			ans=max(ans,newnode1.height);
			newnode1.leftindex=now.leftindex;
			newnode1.rightindex=curpos-1;
			q.push(newnode1);
		}
		if(curpos<now.rightindex){
			Node newnode1;
			newnode1.height=now.height+1;
			ans=max(ans,newnode1.height);
			newnode1.leftindex=curpos+1;
			newnode1.rightindex=now.rightindex;
			q.push(newnode1);
		}
	}
	return ans;
	// Write your code here.
}
