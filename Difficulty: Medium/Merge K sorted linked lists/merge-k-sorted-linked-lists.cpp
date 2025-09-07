/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* mergeTwoLists(Node* l1, Node* l2) {
        Node* dummy = new Node(0);
        Node* tail = dummy;
        while (l1 && l2) {
            if (l1->data <= l2->data) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        if (l1){
            tail->next = l1;
        }
        if (l2) {
        tail->next = l2;
        }
        
        Node* res = dummy->next;
        delete dummy;
        return res;
    }
    Node* mergeKLists(vector<Node*>& arr) {
        if (arr.empty()) return NULL;

        Node* head = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            head = mergeTwoLists(head, arr[i]);
        }
        return head;
    }
};
