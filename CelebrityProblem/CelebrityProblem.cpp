//https://www.codingninjas.com/codestudio/problems/the-celebrity-problem_982769?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

// Brute Force - Use 2 loops to compare each and every one 
// TC : O(N*2)
// SC : O(1)

// Efficient Approach - Use stack
#include <stack>;
int findCelebrity(int n) {
    stack<int> st;
    for(int i=0; i<n; i++){
        st.push(i);
    }
    
    while(st.size()>1){
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        
        if(knows(a,b)) st.push(b);
        else st.push(a);
    }
    
    for(int i = 0; i<n; i++){
        if(i!=st.top() && knows(st.top(),i)){
            return -1;
        }
    }
    
    for(int i = 0; i<n; i++){
        if(i!=st.top() && !knows(i,st.top())){
             return -1;
        }
    }
    
    return st.top();
}
// TC : O(N)
// SC : O(N)