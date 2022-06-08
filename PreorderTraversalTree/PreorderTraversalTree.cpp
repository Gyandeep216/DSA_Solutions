// https://leetcode.com/problems/binary-tree-preorder-traversal/

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

// Recursive Approach
class Solution {
public:
    vector<int> ans;
    vector<int> preorderTraversal(TreeNode* root) {
        helper(root);
        return ans;
    }
    
    void helper(TreeNode* root){
        if(root == NULL) return;
        ans.push_back(root->val);
        helper(root->left);
        helper(root->right);
    }
};

// Iterative Approach
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* curr = root;
        vector<int> preorder;
        
        while(true){
            if(curr!=NULL){
                preorder.push_back(curr->val);
                st.push(curr);
                curr = curr->left;
            }else{
                if(st.empty()) break;
                curr = st.top();
                st.pop();
                curr = curr->right;
            }
        }
        
        return preorder;
    }
};

// TC : O(N)
// SC : O(N)