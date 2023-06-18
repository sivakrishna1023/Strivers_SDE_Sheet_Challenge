#include <bits/stdc++.h> 

struct Node{
    Node *links[26];
    bool flag=false;
    
    bool containsKey(char c){
        if(links[c-'a']==NULL) return false;
        return true;
    }
    void put(char c,Node *node,int &count){
        count++;
        links[c-'a']=node;
    }
    Node *get(char c){
        return links[c-'a'];
    }
    void setend(){
        flag=true;
    }
};
int distinctSubstring(string &word) {
    //  Write your code here.
    int count=0;
    Node * root=new Node();
    for(int i=0;i<word.size();i++){
        Node *node=root;
        for(int j=i;j<word.size();j++){
            if(!node->containsKey(word[j])){
                node->put(word[j],new Node(),count);
            }
            node=node->get(word[j]);
            node->setend();
        }
    }
    return count;
}
// int distinctSubstring(string &word) {
//     int n=word.size();set<string> s;
//    for (int i = 0; i < n; i++) {
//         for (int len = 1; len <= n - i; len++) {
//            s.insert(word.substr(i, len)); 
//         }
//     }
//     return (int)s.size();
//     //  Write your code here.
// }
