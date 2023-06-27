#include<bits/stdc++.h>
class Queue {
    // Define the data members(if any) here.
    
    public:
    stack<int> s;
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) {
        stack<int> temp; 
        while(!s.empty()){
            temp.push(s.top());s.pop();
        }
        temp.push(val);
        while(!temp.empty()){
                s.push(temp.top());temp.pop();
        }
        // Implement the enqueue() function.
    }

    int deQueue() {
        if(s.size()==0) return -1;
        int v=s.top();s.pop();
        return v;
        // Implement the dequeue() function.
    }

    int peek() {
        if(s.size()==0) return -1;
        else return s.top();
        // Implement the peek() function here.
    }

    bool isEmpty() {
        if(s.size()==0) return true;
        else return false;
        // Implement the isEmpty() function here.
    }
};
