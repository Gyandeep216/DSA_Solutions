//https://www.codingninjas.com/codestudio/problems/childrensumproperty_790723?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void changeTree(BinaryTreeNode < int > * root) {
    if(root == NULL) return;
    
    int sumChild = 0;
    if(root->left) sumChild += root->left->data;
    if(root->right) sumChild += root->right->data;
    
    if(root->data >= sumChild){
        if(root->left) root->left->data = root->data;
        if(root->right) root->right->data = root->data;
    }else{
        root->data = sumChild;
    }
    
    changeTree(root->left);
    changeTree(root->right);
    
    int sumTotal = 0;
    if(root->left) sumTotal += root->left->data;
    if(root->right) sumTotal += root->right->data;
    
    if(root->left || root->right) root->data = sumTotal;

}  
// TC : O(N)
// SC : O(N)