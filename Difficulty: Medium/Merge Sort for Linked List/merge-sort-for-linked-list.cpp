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
    Node* mergeSort(Node* head) {
        if(!head) return head;
        
        vector<int>p;
        Node *temp=head;
        while (temp) { 
            p.push_back(temp->data);
            temp = temp->next;
        }
        sort(p.begin(), p.end());
        temp=head;
         for (int i = 0; i < p.size(); i++) {
            temp->data = p[i];
            temp = temp->next;
        }
        return head;
    }
};