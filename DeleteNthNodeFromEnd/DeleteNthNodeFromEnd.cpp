// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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

//Brute Force
class Solution {
public:
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      
        int l = 0;
        ListNode* temp1 = head;
        while(temp1!=NULL){
            temp1 = temp1->next;
            l++;
        }
        
        if(n == l){
            ListNode* todelete = head;
            head = head->next;
            delete todelete;
            return head;
        }
        
        
        int pos = l-n-1;
        
        ListNode* temp2 = head;
        while(pos--){
            temp2 = temp2->next;
        }
        
        ListNode* todelete = temp2->next;
        if(temp2->next!=NULL)
            temp2->next = temp2->next->next;
        else
            temp2->next = NULL;
        delete todelete;
        return head;
        
    }        
        
};

// TC : O(N)+O(N)
// SC : O(1)

// Efficient Approach - Using Slow and Fast pointer
class Solution {
public:
    
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        
        while(n--){
            fast = fast->next;
        }
        
        while(fast->next!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
        
        ListNode* todelete = slow->next;
        slow->next = slow->next->next;
        delete todelete;
        return dummy->next;
        
    }
};

// TC : O(N)
// SC : O(1)