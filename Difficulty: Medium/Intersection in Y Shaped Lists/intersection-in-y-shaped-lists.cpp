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
    Node* intersectPoint(Node* head1, Node* head2) {
       if(!head1 || !head2) return NULL;
        Node *a = head1, *b = head2;
        while(a != b){
            a = a ? a->next : head2;
            b = b ? b->next : head1;
        }
        return a;
    }
};