
// https://leetcode.com/problems/merge-two-sorted-lists/submissions/

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

// Brute Force Approach - Creation of new Linked List
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;
        ListNode* dummy = new ListNode(-1);
        ListNode* ptr3 = dummy;
        
        while(ptr1!=NULL && ptr2!=NULL){
            
            if(ptr1->val<ptr2->val){
                ListNode* temp = new ListNode(ptr1->val);
                ptr3->next = temp;
                ptr1 = ptr1->next;
                ptr3 = ptr3->next;
            }else{
                ListNode* temp = new ListNode(ptr2->val);
                ptr3->next = temp;
                ptr2 = ptr2->next;
                ptr3 = ptr3->next;
            }
        }
        
         while(ptr1!=NULL){
            ListNode* temp = new ListNode(ptr1->val);
            ptr3->next = temp;
            ptr1 = ptr1->next;
            ptr3 = ptr3->next;
        }
        
        while(ptr2!=NULL){
            ListNode* temp = new ListNode(ptr2->val);
            ptr3->next = temp;
            ptr2 = ptr2->next;
            ptr3 = ptr3->next;
        }
        
        return dummy->next;
        
    }
};
// TC - O(M+N)
// SC - O(M+N)

// Efficient Approaches - Inplace Merge
// Iterative Approach
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* ptr1 = list1;
        ListNode* ptr2 = list2;
        ListNode* ptr3 = dummy;
        
        while(ptr1!=NULL && ptr2!=NULL){
            if(ptr1->val < ptr2->val){
                ptr3->next = ptr1;
                ptr1 = ptr1->next;   
            }else{
                ptr3->next = ptr2;
                ptr2 = ptr2->next;
            }
            ptr3 = ptr3->next;
        }
        
        while(ptr1!=NULL){
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
            ptr3 = ptr3->next;
        }
        
        while(ptr2!=NULL){
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
            ptr3 = ptr3->next;
        }
        
        return dummy->next;
    }
};
// TC - O(M+N)
// SC - O(1)

// Recurrsive Approach
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* result;
        
        if(list1 == NULL){
            return list2;
        }
        
        if(list2 == NULL){
            return list1;
        }
        
        if(list1->val < list2->val){
            result = list1;
            result->next = mergeTwoLists(list1->next,list2);
        }else{
            result = list2;
            result->next = mergeTwoLists(list1,list2->next);
        }
        
        return result;
        
    }
};
// TC - O(M+N)
// SC - O(1)