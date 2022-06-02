//https://leetcode.com/problems/min-stack/

//Brute Force - Using supporting Stack can be done easily by pushing the min elements to the new stack and popping as needed

//Min Stack in O(1) space complexity
class MinStack {
public:
    stack<long long> st;
    long long minele;
    
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            minele = val;
            st.push(val);
            return;
        }
        
        if(val<minele){
            st.push(2*(long long)val-minele);
            minele = val;
        }else{
            st.push(val);
        }        
        
    }
    
    void pop() {
        if(st.top()<minele){
            minele = 2*minele - st.top();
        }
        
        st.pop();
    }
    
    int top() {
        if(st.top()<minele) return minele;
        else return st.top();
    }
    
    int getMin() {
        return minele;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

 // TC : O(N)
 // SC : O(1)