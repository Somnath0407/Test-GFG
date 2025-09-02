/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* swapKth(Node* head, int k) {
        
    if (!head) return head;

    Node* first = head;
    for (int i = 1; i < k && first; i++) {
        first = first->next;
    }
    if (!first) return head;

    Node* fast = first;
    Node* second = head;
    while (fast->next) {
        fast = fast->next;
        second = second->next;
    }

    if (first == second) return head;

    swap(first->data, second->data);
    return head;
    }    
};