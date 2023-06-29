#include <bits/stdc++.h> 
struct Node{
    Node * links[2];
    bool iscontain(int n){
        return (links[n]!=NULL);
    }
    Node* get(int n){
        return links[n]; 
    }
    void put(int n,Node* newnode){
        links[n]=newnode;
    }
};
class Trie{
public:
    Node* root;
    Trie(){
        root= new Node();
    }
    void insert(int num){
        Node* node=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(!node->iscontain(bit)){
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }
    int maxnum(int num){
        Node* node=root;
        int val=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(node->iscontain(1-bit)){
                val=val | (1<<i);
                node=node->get(1-bit);
            }
            else{
                node=node->get(bit);
            }
        }
        return val;
    }
};
int maximumXor(vector<int> A)
{  
    Trie t;
    for(int i=0;i<A.size();i++){
        t.insert(A[i]);
    }
    int ans=0;
    for(int i=0;i<A.size();i++){
        ans=max(ans,t.maxnum(A[i]));
    }
    return ans;
    // Write your code here.   
}
