// class Node {
//   public:
//     int data;
//     Node* next;

//     Node(int x){
//         data = x;
//         next = NULL;
//     }
// };

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        struct compare {
            bool operator()(Node* a, Node* b) {
                return a->data > b->data; // min-heap
            }
        };

        priority_queue<Node*, vector<Node*>, compare> pq;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i]) pq.push(arr[i]);
        }

        Node* dummy = new Node(0);
        Node* tail = dummy;

        while (!pq.empty()) {
            Node* t = pq.top();
            pq.pop();
            tail->next = t;
            tail = tail->next;
            if (t->next) pq.push(t->next);
        }
        return dummy->next;
    }
};
