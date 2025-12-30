/*
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
  Node * reverse(Node* head){
      Node* prev=NULL,*curr=head;
      while(curr){
          Node *nex=curr->next;
          curr->next=prev;
          prev=curr;
          curr=nex;
      }
      return prev;
  }
  Node *trim(Node* head){
      while(head && head->data==0){
          head=head->next;
      }
      return head?head :new Node(0);
  }
    Node* addTwoLists(Node* head1, Node* head2) {
        head1 = trim(head1);
        head2 = trim(head2);
        head1 = reverse(head1);
        head2 = reverse(head2);
        Node* dummy = new Node(-1);
        Node* curr = dummy;
        int carry = 0;
        while(head1 || head2 ||carry){
            int sum=carry;
            if(head1){
                sum+=head1->data;
                head1=head1->next;
            }
            if(head2){
                sum+=head2->data;
                head2=head2->next;
            }
            curr->next=new Node(sum%10);
            curr=curr->next;
            carry=sum/10;
        }
        Node* res = reverse(dummy->next);
        return trim(res);
    }
};