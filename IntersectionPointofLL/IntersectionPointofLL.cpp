//https://leetcode.com/problems/intersection-of-two-linked-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Brute Force - Simply run 2 loops to check every node of each linked list if they are equal.
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ptrA = headA;
        ListNode* ptrB = headB;
        
        while(ptrA!=NULL){
            while(ptrB!=NULL){
                if(ptrA==ptrB) return ptrA;
                ptrB = ptrB->next;
            }
            ptrB = headB;
            ptrA = ptrA->next;
        }
        
        return NULL;
    }
};
// TC : O(M*N)
// SC : O(1)

// Better Approach - Use hashing to hash all nodes of one list and the traverse the other list to compare.
// Code comes here when I learn hashing...
// TC : O(M+N)
// SC : O(N) - For hashing

//Efficient Approach - 1
class Solution{
public:
    
    int length(ListNode* head){
        int l=1;
        ListNode* temp = head;
        
        while(temp->next!=NULL){
            l++;
            temp = temp->next;
        }
        
        return l;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            
        int l1 = length(headA);
        int l2 = length(headB);
        int d = abs(l1-l2);
        
        ListNode* ptr1;
        ListNode* ptr2;
        
        if(l1>l2){
            ptr1 = headA;
            ptr2 = headB;
        }else{
            ptr1 = headB;
            ptr2 = headA;
        }
        
        while(d--){
            ptr1 = ptr1->next;
        }
        
        while(ptr1!=NULL && ptr2!=NULL){
            if(ptr1 == ptr2) return ptr1;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        return NULL;
    }
};
// TC : O(M+N)
// SC : O(1)

// Modified Efficient Approach - Same one just modified to have shorter code
// Striver's Solution
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL) return NULL;
        
        ListNode* ptrA = headA;
        ListNode* ptrB = headB;
        
        //We interate both pointers simultaneously. Once one reaches NULL we put it to the head of the other list. In second iteration they will be at equal distance from intersection point or they will meet at NULL.
        while(ptrA!=ptrB){ //If no intersection exists they meet at null
            
            ptrA = ptrA==NULL ? headB : ptrA->next;
            ptrB = ptrB==NULL ? headA : ptrB->next;
        }
        
        return ptrA;
    }
};
// TC : O(M+N)
// SC : O(1)