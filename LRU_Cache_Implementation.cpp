#include<bits/stdc++.h>
class LRUCache
{
public:
    int cap;
    unordered_map<int,list<pair<int,int>>::iterator> mp;
    list<pair<int,int>> l;
    
    LRUCache(int capacity)
    {
        this->cap=capacity;
        // Write your code here
    }

    int get(int key)
    {
        if(mp.find(key)==mp.end()) return -1;
        else{
            auto ele=mp[key];
            int val=ele->second;
            l.erase(ele);
            l.push_front({key,val});
            mp[key]=l.begin();
            return val;
        }
        // Write your code here
    }

    void put(int key, int value)
    {
        if(mp.find(key)!=mp.end()){
            l.erase(mp[key]);
            mp.erase(key);
        }
        if(cap==l.size()){
            auto val= l.back();
            l.erase(mp[val.first]);
            mp.erase(val.first);
        }
        l.push_front({key,value});
        mp[key]=l.begin();
        // Write your code here
    }
};
