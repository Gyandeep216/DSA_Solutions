// https://leetcode.com/problems/3sum/

// Brute Force - Use 3 loops to cover each and every possible arrangement
// TC : O(N^3)
// SC : O(1)

// Efficient Approach - 2 pointer approach
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            int high = n-1, low = i+1;
            while(low<high){
                if(nums[i] + nums[high] + nums[low] == 0){
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[high]);
                    temp.push_back(nums[low]);
                    ans.push_back(temp);
                    
                    while(low < high && nums[low] == nums[low+1]) low++; 
                    while(high > low && nums[high] == nums[high-1]) high--;
                    low++;
                    high--;
                    
                }
                else if(nums[i] + nums[high] + nums[low] < 0) low++;
                else high--;
                
            }
            while(i+1 < n && nums[i+1] == nums[i]) i++;
        }
        return ans;
    }
};
// TC : O(N^2)
// SC : O(1)