//https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        maxRecurse(root,ans);
        return ans;

    }
    
    int maxRecurse(TreeNode* root, int &ans){
        if(root == NULL) return 0;
        
        int leftMax = max(0,maxRecurse(root->left, ans));
        int rightMax = max(0,maxRecurse(root->right, ans));
        ans = max(ans, leftMax+rightMax+root->val);
        
        return root->val+max(leftMax,rightMax);
    }
};

// TC : O(N)
// SC : O(N)