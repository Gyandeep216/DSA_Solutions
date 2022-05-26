#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int val;
    node* next;

    node(int data){
        val = data;
        next = NULL;
    }
};

void insertAtTail(int data, node* &head){

    node* n = new node(data);

    if(head == NULL){
        head = n;
        return;
    }

    node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = n;

}

void display(node* head){

    if(head == NULL){
        return;
    }

    node* temp = head;
    while(temp!=NULL){
        cout<<temp->val<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;

}

node* reverseIterative(node* &head){

    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;

    while(currptr!=NULL){
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nextptr;
    }

    return prevptr;
}

node* reverseRecurrsive(node* &head){

    if(head == NULL || head->next == NULL){
        return head;
    }

    node* newhead = reverseRecurrsive(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;

}


int main(){
    node* head = NULL;
    insertAtTail(1,head);
    insertAtTail(2,head);
    insertAtTail(3,head);
    insertAtTail(4,head);
    display(head);
    
    // node* newhead1 = reverseIterative(head);
    // display(newhead1);

    node* newhead2 = reverseRecurrsive(head);
    display(newhead2);

    return 0;
}
