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
// Brute Force using recurrsion
class Solution {
public:
     TreeNode* prev = NULL;
    
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        
        flatten(root->right);
        flatten(root->left);
            
        root->right = prev;
        root->left = NULL;
            
        prev = root;
    }
};
// TC : O(N).
// SC : O(N)

// Brute Force Using stack
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL){
            return;
        }
        
        stack<TreeNode*> st;
        st.push(root);
        
        while(!st.empty()){
            TreeNode* curr = st.top();
            st.pop();
            
            if(curr->right) st.push(curr->right);
            if(curr->left) st.push(curr->left);
            
            if(!st.empty()){
                curr->right = st.top();
                curr->left = NULL;
            }
        }
    }
};
// TC : O(N).
// SC : O(N)

// Efficient Algorithm using Morris Traversal Approach
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL){
            return;
        }
        
        TreeNode* curr = root;
        
        while(curr){
            if(curr->left){
                TreeNode* prev = curr->left;
                while(prev->right){
                    prev = prev->right;
                }
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};
// TC : O(N)
// SC : O(1)


