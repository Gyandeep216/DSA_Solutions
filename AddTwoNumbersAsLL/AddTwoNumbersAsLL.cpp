//https://leetcode.com/problems/add-two-numbers/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        
        int carry = 0;
        
        ListNode* dummy = new ListNode(-1);
        ListNode* ptr3 = dummy;
        
        while(ptr1!=NULL && ptr2!=NULL){

            int data = ptr1->val + ptr2->val + carry;
            int res = data%10;
            carry = data/10;
            
            ListNode* newNode = new ListNode(res);
            ptr3->next = newNode;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            ptr3 = ptr3->next;
        }
        
        while(ptr1!=NULL){
            int data = ptr1->val+ carry;
            int res = data%10;
            carry = data/10;
            
            ListNode* newNode = new ListNode(res);
            ptr3->next = newNode;
            ptr1 = ptr1->next;
            ptr3 = ptr3->next;
        }
        
        while(ptr2!=NULL){
            int data = ptr2->val+ carry;
            int res = data%10;
            carry = data/10;
            
            ListNode* newNode = new ListNode(res);
            ptr3->next = newNode;
            ptr2 = ptr2->next;
            ptr3 = ptr3->next;
        }
        
        if(carry!=0){
            ListNode* newNode = new ListNode(carry);
            ptr3->next = newNode;    
        }
        
        return dummy->next;
    }
};

// TC : O(max(M,N))
// SC : O(max(M,N))