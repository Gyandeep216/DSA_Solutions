//https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1#

/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */

Node* merge(Node* list1, Node* list2){
    
    Node* dummy = new Node(-1);
    Node* ptr1 = list2;
    Node* ptr2 = list1;
    Node* ptr3 = dummy;
    
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->data < ptr2->data){
            ptr3->bottom = ptr1;
            ptr1 = ptr1->bottom;
        }else{
            ptr3->bottom = ptr2;
            ptr2 = ptr2->bottom;
        }
        ptr3 = ptr3->bottom;
    }
    
    while(ptr1!=NULL){
        ptr3->bottom = ptr1;
        ptr1 = ptr1->bottom;
        ptr3 = ptr3->bottom;
    }
    
    while(ptr2!=NULL){
        ptr3->bottom = ptr2;
        ptr2 = ptr2->bottom;
        ptr3 = ptr3->bottom;
    }
    
    return dummy->bottom;
}

Node *flatten(Node *root)
{
    if(root == NULL || root->next == NULL){
        return root;
    }
    
    root->next = flatten(root->next);
    
    root = merge(root,root->next);
    
    return root;
}
// TC : O(N); N = Total Number of nodes
// SC : O(1) 
 
