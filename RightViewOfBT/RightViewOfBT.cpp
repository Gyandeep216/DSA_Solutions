// https://leetcode.com/problems/binary-tree-right-side-view/

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        recurse(root,0, ans);
        return ans;
    }
    
    void recurse(TreeNode* root, int level, vector<int> &ans){
        if(root == NULL) return;
        if(ans.size()==level) ans.push_back(root->val);
        recurse(root->right , level+1, ans);
        recurse(root->left , level+1, ans);
    }
};
// TC : O(N)
// SC : O(H) / O(N) -> worst case(skew tree)