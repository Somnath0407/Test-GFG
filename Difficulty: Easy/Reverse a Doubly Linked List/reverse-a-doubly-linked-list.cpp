/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        if(!head) return NULL;
        
        Node *temp=NULL;
        Node*curr=head;
        while(curr){
            temp=curr->prev;
            curr->prev=curr->next;
            curr->next=temp;
            curr=curr->prev;
        }
        if (temp) head = temp->prev;
        return head;
    }
};