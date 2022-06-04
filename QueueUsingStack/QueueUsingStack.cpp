//https://leetcode.com/problems/implement-queue-using-stacks/

// Brute Force -
class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    
    void push(int x) {
       while(!s1.empty()){
           s2.push(s1.top());
           s1.pop();
       }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        
    }
    
    int pop() {
        
        int val = s1.top();
        s1.pop();
        return val;
    }
    
    int peek() {
      return s1.top();
    }
    
    bool empty() {
        if(s1.empty()) return true;
        return false;
    }
};
// TC : O(N)
// SC : O(2N)

// Efficient Approach - Amortized O(1)
class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int val = s2.top();
        s2.pop();
        return val;
    }
    
    int peek() {
       if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() {
        if(s1.empty() && s2.empty()) return true;
        return false;
    }
};
// TC : O(1) -> Amortized since most of the time all the operations will be taking O(1) and only sometimes the push and top will take O(N)
// SC : O(2N) = O(N)

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */