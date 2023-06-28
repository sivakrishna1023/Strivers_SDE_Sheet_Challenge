#include <bits/stdc++.h> 
struct Node{
    Node* links[26];
    int wordend=0;
    int cntpre=0;
    bool isfound(char c){
        return (links[c-'a']!=NULL);
    }
    Node* get(char c){
        return links[c-'a'];
    }
    void put(char c,Node* node){
        links[c-'a']=node;
    }
    void increaseend(){
           wordend++;
    }
    void increasecnt(){
        cntpre++;
    }
    void delend(){
        wordend--;
    }
    void decresepre(){
        cntpre--;
    }
    int getend(){
        return wordend;
    }
    int getpre(){
        return cntpre;
    }
};
class Trie{
    Node* root;
    public:
    
    Trie(){
        root = new Node();
        // Write your code here.
    }

    void insert(string &word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(!node->isfound(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
            node->increasecnt();
        }
        node->increaseend();
        // Write your code here.
    }

    int countWordsEqualTo(string &word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(node->isfound(word[i])){
                node=node->get(word[i]);
            }
            else{
                return 0;
            }
        }
        return node->getend();
        // Write your code here.
    }

    int countWordsStartingWith(string &word){
        Node* node=root;
        for(int i=0;i<word[i];i++){
            if(node->isfound(word[i])){
                node=node->get(word[i]);
            }
            else{
                return 0;
            }
        }
        return node->getpre();
        // Write your code here.
    }

    void erase(string &word){
        Node* node=root;
        for(int i=0;i<word.size();i++){
            if(node->isfound(word[i])){
                node=node->get(word[i]);
                node->decresepre();
            }
            else{
                return;
            }
        }
        node->delend();
        // Write your code here.
    }
};
