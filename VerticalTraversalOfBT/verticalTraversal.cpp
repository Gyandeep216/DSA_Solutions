//https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});        
        map<int,map<int,multiset<int>>> mp;
        
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int vertical = q.front().second.first;
            int level = q.front().second.second;
            q.pop();
            
            mp[vertical][level].insert(node->val);
            
            if(node->left){
                q.push({node->left,{vertical-1,level+1}});
            }
            
            if(node->right){
                q.push({node->right,{vertical+1,level+1}});
            }
        }
        
         vector<vector<int>> ans;

        for(auto it1 : mp){
            vector<int> col;
            for(auto it2 : it1.second){
                col.insert(col.end(),it2.second.begin(),it2.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};
// TC : O(NlogN) - logN due to hashmap
// SC : O(N)