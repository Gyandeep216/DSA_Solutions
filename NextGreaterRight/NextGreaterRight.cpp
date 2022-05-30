//https://leetcode.com/problems/next-greater-element-i/

// Efficient Approach
// Modified of the original code to complete the solution in O(nums1+nums2) by inserting taking the values of nums2 as indexes to store the answers in the ans array. Then printing the answers at the particular array by taking nums1's values.

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int> st;
        vector<int> ans(10000,-1);
        
        for(int i=nums2.size()-1; i>=0; i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if(st.empty()){
                ans[nums2[i]]=-1;
            }else{
                ans[nums2[i]]=st.top();
            }
            st.push(nums2[i]);
        }
        
        vector<int> res;
    
        for(int i=0; i<nums1.size(); i++){
            res.push_back(ans[nums1[i]]);
        }
        
        return res;
    }
     
};

// TC : O(nums1+nums2)
// SC : O(nums2)