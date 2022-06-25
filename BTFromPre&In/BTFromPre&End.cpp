//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
    unordered_map<int,int> index;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i<inorder.size(); i++){
            index[inorder[i]] = i;
        }
        TreeNode* root = treeBuild(preorder, 0, preorder.size()-1, inorder, 0,                  inorder.size()-1);
        
        return root;
    }
    
    TreeNode* treeBuild(vector<int> preorder, int preStart, int preEnd, vector<int> inorder, int inStart, int inEnd){
        if(preStart>preEnd || inStart > inEnd) return NULL;
        
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = index[root->val];
        int numsLeft = inRoot - inStart;
        
        root->left = treeBuild(preorder, preStart+1, preStart+numsLeft, inorder, inStart, inRoot-1);
        root->right = treeBuild(preorder, preStart+numsLeft+1, preEnd, inorder, inRoot+1, inEnd);
        
        return root;
    }
};
// TC : O(NlogN) or O(N) depending on TC of map used
// SC : O(N)