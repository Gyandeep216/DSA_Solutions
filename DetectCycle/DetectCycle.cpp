//https://leetcode.com/problems/linked-list-cycle/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Brute Force - Use hash table to keep note of all the visited nodes. If cycle exists one of the nodes will be repeated.
// Code comes here when I learn hashing ...
// TC : O(N)
// SC : O(N)

// Efficient Approach - Floyd's Algorithm 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast!=NULL && fast->next!=NULL){
             fast = fast->next->next;
             slow = slow->next;
            
            if(fast == slow){
                return true;
            }
           
        }
        
        return false;
    }
};

// TC : O(N)
// SC : O(1)