// https://leetcode.com/problems/copy-list-with-random-pointer/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// Efficient Solution
class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        Node* first = head;
        Node* second = head;
        
        //At first iteration we insert the new nodes adjacent to the original nodes
        while(second!=NULL){
            second = first->next;
            Node* n = new Node(first->val);
            first->next = n;
            n->next = second;
            first = second;
        }
        
        first = head;
        
        //At Second iteration we make all the randoms of the new nodes equal to the next of the randoms of the original nodes
        while(first!=NULL){
            if(first->random!=NULL){
                first->next->random = first->random->next;
            }
            
            first = first->next->next;
        }
        
        first = head;
        Node* dummy = new Node(-1);
        Node* ptr = dummy;
        
        //At third iteration we separate the 2 lists by modifying the links such that dummy->next becomes the required head of the new linked list and the original links remain intact as it was before
        while(first!=NULL){
            ptr->next = first->next;
            first->next = first->next->next;
            first = first->next;
            ptr = ptr->next;
        }
        
        return dummy->next;
        
    }
};
// TC = O(N)+O(N)+O(N) = O(N)
// SC = O(1)