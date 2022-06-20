// https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1

/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        queue<pair<Node*,int>> q;
        q.push({root,0});
        
        map<int,Node*> mp;
        mp[0] = root;
        
        vector<int> ans;
        
        while(!q.empty()){
            Node* node = q.front().first;
            int level = q.front().second;
            q.pop();
            
            if(node->left){
                q.push({node->left,level-1});
                if(!mp[level-1]) mp[level-1] = node->left;
            }
            
            if(node->right){
                q.push({node->right,level+1});
                if(!mp[level+1]) mp[level+1] = node->right;
            }
        }
        
        for(auto it : mp){
            ans.push_back(it.second->data);
        }
        
        return ans;
        
    }

};

// TC : O(NlogN) - logN due to map
// SC : O(N)