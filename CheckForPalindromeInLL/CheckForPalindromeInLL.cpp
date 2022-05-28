//https://leetcode.com/problems/palindrome-linked-list/

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
    bool isPalindrome(ListNode* head) {
        
        ListNode* temp = head;
        int arr[100000];
        
        int count = 0;
        
        while(temp!=NULL){
            arr[count++] = temp->val;
            temp = temp->next;
        }
        
        int init = 0;
        count--;
        
        while(init<=count){
            if(arr[init++]==arr[count--]){
                continue;
            }else{
                return false;
            }
        }
        
        return true;
    }
};

// TC : O(N)+O(N) = O(N)
// SC : O(N)

// Efficient Solution
class Solution {
public:
    
    ListNode* reverseLL(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next;
        
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    bool isPalindrome(ListNode* head){
        if(head==NULL || head->next==NULL) return true;
       
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* ptr = head;
        
        while(fast->next!=NULL && fast->next->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        slow = slow->next;
        
        slow = reverseLL(slow);
        
        while(slow!=NULL){
           
            if(ptr->val != slow->val){
                return false;
            }
            
            ptr = ptr->next;
            slow = slow->next;
        }
        
        return true;
    }
};
// TC : O(N);;
// SC : O(1)