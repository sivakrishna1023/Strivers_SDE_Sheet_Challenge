#include <bits/stdc++.h> 
class Kthlargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;int size=0;
    Kthlargest(int k, vector<int> &arr) {
        size=k;
        for(int i=0;i<arr.size();i++){
            pq.push(arr[i]);
            if(pq.size()>size){
                pq.pop();
            }
        }
       // Write your code here.
    }

    void add(int num) {
        pq.push(num);
        if(pq.size()>size){
            pq.pop();
        }
        // Write your code here.
    }

    int getKthLargest() {
       return pq.top();
       // Write your code here.
    }

};
