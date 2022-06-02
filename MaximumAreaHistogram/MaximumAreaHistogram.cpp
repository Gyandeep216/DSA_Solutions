//https://leetcode.com/problems/largest-rectangle-in-histogram/

//Efficient Approach using stack - 1
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        vector<int> nsl;
        vector<int> nsr;
        stack<pair<int,int>> st;

        for(int i=0; i<heights.size(); i++){
            while(!st.empty() && st.top().first>=heights[i]) st.pop();
            if(!st.empty() && st.top().first<heights[i]) nsl.push_back(st.top().second);
            else if(st.empty()) nsl.push_back(-1);
            st.push({heights[i],i});
        }
        
        while(!st.empty()){
            st.pop();
        }
        
        for(int i=heights.size()-1; i>=0; i--){
            while(!st.empty() && st.top().first>=heights[i]) st.pop();
            if(!st.empty() && st.top().first<heights[i]) nsr.push_back(st.top().second);
            else if(st.empty()) nsr.push_back(heights.size());
            st.push({heights[i],i});
        }
        
        reverse(nsr.begin(),nsr.end());
        vector<int> width;
        int ans = 0; 
        
        for(int i=0; i<heights.size(); i++){
            width.push_back(nsr[i] - nsl[i] - 1);
        }
        
         for(int i=0; i<heights.size(); i++){
            int area = heights[i]*width[i];
            ans = max(ans,area); 
        }
        
        return ans;
    }
};
// TC : O(N) + O(N) = O(N)
// SC : O(N) + O(N) + O(N) = O(N)

// Most Optimal Solution - Striver's Solution(Less code)
// Everytime we find a greater element on top of stack we find that present element is the NSR for that element and the NSL is the one below it in stack. Doing this allows us to find both in only one pass.
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
    
        stack<pair<int,int>> st;
        int maxA = 0;
        
        for(int i=0; i<=heights.size(); i++){
            while(!st.empty() && (i==heights.size() || st.top().first>=heights[i])){
                int height = st.top().first;
                st.pop();
                int width;
                if(st.empty()) width = i;
                else width = i -st.top().second-1;
                maxA = max(maxA,height*width);
            }
            if(i!=heights.size())
                st.push({heights[i],i});
        }
        return maxA;
    }   
};
// TC : O(N) + O(N)
// SC : O(N)