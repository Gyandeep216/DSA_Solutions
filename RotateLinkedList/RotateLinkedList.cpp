// https://leetcode.com/problems/rotate-list/

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

// Brute Force
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == NULL || head->next==NULL){
            return head;
        }
        
        ListNode* temp = head;
        
        while(k--){
            temp = head;
            while(temp->next->next!=NULL){
                temp = temp->next;
            }
            temp->next->next = head;
            head = temp->next;
            temp->next = NULL;
        }            
        
        return head;
    }
};
// TC : O(K*N)
// SC : O(1)
// Gives TLE in leetcode

// Efficient Approach
class Solution {
public:
    
    int length(ListNode* head){
        ListNode* temp = head;
        int l = 1;
        
        while(temp->next!=NULL){
            l++;
            temp = temp->next;
        }
        
        return l;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == NULL){
            return NULL;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        int l = length(head);
        k = k%l;
        
        while(k--){
            fast = fast->next;
        }
        
        while(fast->next!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
        
        fast->next = head;
        head = slow->next;
        slow->next = NULL;
        
        return head;
        
    }
};