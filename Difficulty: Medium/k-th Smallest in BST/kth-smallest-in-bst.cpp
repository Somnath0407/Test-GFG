/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
public:
    int kthSmallest(Node* root, int k) {
        stack<Node*> st;
        while (root || !st.empty()) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            root = st.top(); 
            st.pop();
            if (--k == 0) return root->data;
            root = root->right;
        }
        return -1;
    }
};
