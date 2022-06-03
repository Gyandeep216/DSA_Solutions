//https://leetcode.com/problems/sliding-window-maximum/

// Brute Force 
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int num = INT_MIN;
        for(int i=0; i<=nums.size()-k; i++){
            int num = INT_MIN;
            for(int j=i; j<i+k; j++){
                num = max(num,nums[j]);
            }
             ans.push_back(num);
        }
        
        return ans;
    }
};
// TC : O(N*K)
// SC : O(1)

// Effcient Approach using deque
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> dq;
        vector<int> ans;
        
        for(int i=0; i<nums.size(); i++){
            
            if(!dq.empty() && dq.front()==i-k) dq.pop_front();
            
            while(!dq.empty() && nums[dq.back()]<nums[i]){
                dq.pop_back();
            }dq.push_back(i);
            
            if(i>=k-1) ans.push_back(nums[dq.front()]);
            
        }
        
        return ans;
    }
};
// TC : O(N)+O(N)=O(N)
// SC : O(N)