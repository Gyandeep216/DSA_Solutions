// https://leetcode.com/problems/linked-list-cycle-ii/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Brute Force - Use hashing to store each node and everytime check if node is already in hash table. That node is the answer. If no cycle exists, we will have NULL in the hash table.
// Code here when I learn hashing
// TC : O(N)
// SC : O(N)

//Efficient Approach - Floyd's slow & fast pointer algorithm 
class Solution {
public:
    
    ListNode* startNode(ListNode* head, ListNode* slow){
        ListNode* ptr = head;
        
        if(ptr == slow){
            return head;
        }
        
        while(ptr->next!=slow->next){
            slow = slow->next;
            ptr = ptr->next;
        }
        
        return slow->next;
    }
    ListNode *detectCycle(ListNode *head) {
        
        if(head==NULL) return NULL;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast){
                ListNode* ans = startNode(head,slow);
                return ans;
            }
        }
        
        return NULL;
    }
};
// TC : O(N)
// SC : O(1)