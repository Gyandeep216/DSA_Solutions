class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int count=0,index;
        ListNode* temp=head;
        while(temp!=NULL)     //calculate length of list.
        {
            count++;
            temp=temp->next;
        }
        if(count==1) return head;
        index=(count/2)+1;        //find the middle element using middle index
        while(index-->1)
        {
            head=head->next;       //travel till that Node and return link
        }
        return head;
    }
};

// Time: O(N) + O(N/2)
// Aux Space: O(1)
