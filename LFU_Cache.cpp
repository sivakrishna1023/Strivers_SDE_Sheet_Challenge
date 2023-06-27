#include <bits/stdc++.h> 
class LFUCache
{
public:
    stack<pair<int,int>> s;int num;
    LFUCache(int capacity)
    { num=capacity;
        // Write your code here.
    }

    int get(int key)
    { stack<pair<int,int>> s1=s;
        while(!s1.empty()){
            if(s1.top().first==key) return s1.top().second;
            s1.pop();
        }
        return -1;
        // Write your code here.
    }

    void put(int key, int value)
    {
        if(s.size()==num){
            s.pop();
            s.push({key,value});
        }
        else{
            s.push({key,value});
        }
        // Write your code here.
    }
};
