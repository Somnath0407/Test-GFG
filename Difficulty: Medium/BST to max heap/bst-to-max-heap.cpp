// User function Template for C++

/*struct Node {
    int data;
    Node *left, *right;
};*/

class Solution {
  public:
    // helper: inorder traversal to collect BST elements
    void inorder(Node* root, vector<int>& arr) {
        if (!root) return;
        inorder(root->left, arr);
        arr.push_back(root->data);
        inorder(root->right, arr);
    }

    // helper: postorder traversal to assign values
    void postorder(Node* root, vector<int>& arr, int &idx) {
        if (!root) return;
        postorder(root->left, arr, idx);
        postorder(root->right, arr, idx);
        root->data = arr[idx++];
    }

    // main function to convert BST → Max Heap
    void convertToMaxHeapUtil(Node* root) {
        vector<int> arr;
        inorder(root, arr);       // get sorted values from BST
        int idx = 0;
        postorder(root, arr, idx); // assign in postorder
    }
};
