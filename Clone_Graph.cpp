#include <bits/stdc++.h> 
/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/
graphNode *cloneGraph(graphNode *node)
{
	//return node;
	if(!node) return NULL;
	graphNode* copynode= new graphNode(node->data);
	unordered_map<graphNode*,graphNode*> mp;
	mp[node]=copynode;
	queue<graphNode*> q;
	q.push(node);
	while(!q.empty()){
		auto temp=q.front();
		q.pop();
		for(auto vals:temp->neighbours){
			if(mp.find(vals)==mp.end()){
				graphNode* c=new graphNode(vals->data);
				mp[vals]=c;
				q.push(vals);
			}
			mp[temp]->neighbours.push_back(mp[vals]);
		}
	}
	return copynode;
    // Write your code here.
}
