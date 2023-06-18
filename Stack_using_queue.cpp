#include <bits/stdc++.h> 
class Stack {
	// Define the data members.

   public:
    queue<int> q;
    Stack() {
        
        // Implement the Constructor.
    }
    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return (int)q.size();
        // Implement the getSize() function.
    }

    bool isEmpty() {
        if(q.size()==0) return true;
        else  return false;
        // Implement the isEmpty() function.
    }

    void push(int element) {

        int n=q.size();
        q.push(element);
        while(n--){
           // cout<<q.front()<<" ";
            q.push(q.front());
            q.pop();
        }
      //  cout<<endl;
        // Implement the push() function.
    }

    int pop() {
        if(q.size()==0) return -1;
        int temp=q.front();
        q.pop();
        return temp;
        // Implement the pop() function.
    }

    int top() {
        if(q.size()==0) return -1;
        int temp=q.front();
        return temp;
        // Implement the top() function.
    }
};
