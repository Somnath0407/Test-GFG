/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    Node* removekeys(Node* root, int l, int r) {
        if (!root) return nullptr;
        root->left = removekeys(root->left, l, r);
        root->right = removekeys(root->right, l, r);
        if (root->data < l) return root->right;
        if (root->data > r) return root->left;
        return root;
        
    }
};