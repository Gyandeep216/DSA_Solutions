//https://leetcode.com/problems/balanced-binary-tree/

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
    bool isBalanced(TreeNode* root) {
        if(balanced(root)==-1) return false;
        return true;
    }
    
    int balanced (TreeNode* root){
        if(root == NULL) return 0;
        int lh = balanced(root->left);
        int rh = balanced(root->right);
        if(lh == -1 || rh == -1 || abs(lh-rh)>1) return -1;
        return 1+max(lh,rh);
    }
};
// TC : O(N)
// SC : O(N)