//https://leetcode.com/problems/binary-tree-postorder-traversal/

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
    vector<int> postorderTraversal(TreeNode* root) {
        helper(root);
        return ans;
    }
    
    void helper(TreeNode* root){
        if(root == NULL) return;
        helper(root->left);
        helper(root->right);
        ans.push_back(root->val);
    }
};
// TC : O(N)
// SC : O(N)

// Iterativer Approach -  Using 2 stacks
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        vector<int> postorder;
        st1.push(root);
        
        if(root == NULL) return postorder;

        
        while(!st1.empty()){
            root = st1.top();
            st1.pop();
            st2.push(root);
            
            if(root->left!=NULL) st1.push(root->left);
            if(root->right!=NULL) st1.push(root->right);
        }
        
        while(!st2.empty()){
            postorder.push_back(st2.top()->val);
            st2.pop();
        }
        
        return postorder;
    }
};
// TC : O(N)
// SC : O(2N)

// Iterative Approach - using 1 stack
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> postorder;
        if(root==NULL) return postorder;
        
        while(root!=NULL || !st.empty()){
            
            if(root!=NULL){
                st.push(root);
                root = root->left;
            }else{
                TreeNode* temp = st.top()->right;
                if(temp == NULL){
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->val);
                    while(!st.empty() && temp == st.top()->right){
                         temp = st.top();
                         st.pop();
                         postorder.push_back(temp->val);
                    }
                }else{
                    root = temp;
                }
            }
        }
        
        return postorder;
    }
};
// TC : O(2N)
// SC : O(N)