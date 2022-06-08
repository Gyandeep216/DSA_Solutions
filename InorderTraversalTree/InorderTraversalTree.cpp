

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

//Using Recurrsion
class Solution {
public:
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root) {
        helper(root);
        return ans;
    }
    void helper(TreeNode* root){
        if(root == NULL) return;
        helper(root->left);
        ans.push_back(root->val);
        helper(root->right);
    }
};

//Using Iterative Approach
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        stack<TreeNode*> st;
        vector<int> inorder;
        
        while(true){
            if(curr!=NULL){
                st.push(curr);
                curr = curr->left;
            }else{
                if(st.empty()) break;
                curr = st.top();
                st.pop();
                inorder.push_back(curr->val);
                curr = curr->right;
            }
        }
        
        return inorder;
    }
};
// TC : O(N)
// SC : O(N)