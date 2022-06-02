//https://www.interviewbit.com/problems/nearest-smaller-element/

// Brute Force same as NGR
// TC : O(N^2)
// SC : O(1)

//Efficient Approach
vector<int> Solution::prevSmaller(vector<int> &A) {
    stack<int> st;
    vector<int> ans;

    for(int i=0; i<A.size(); i++){
        while(!st.empty() && st.top()>=A[i]) st.pop();
        if(!st.empty() && st.top()<A[i]) ans.push_back(st.top());
        else if(st.empty()) ans.push_back(-1);

        st.push(A[i]);
    }

    return ans;
}
// TC : O(N)
// SC : O(N)
