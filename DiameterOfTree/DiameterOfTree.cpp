//https://leetcode.com/problems/diameter-of-binary-tree/

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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        diameter(root, ans);
        return ans;
    }
    
    int diameter(TreeNode* root, int &ans){
        if(root == NULL) return 0;
        int lh = diameter(root->left, ans);
        int rh = diameter(root->right, ans);
        ans = max(ans, lh+rh);
        
        return (1+max(lh,rh));
    }
    
};

// TC : O(N)
// SC : O(N)