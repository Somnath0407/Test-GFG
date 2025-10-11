/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int ans;
    int sum(Node* root){
        if(!root) return 0;
        int l = max(0, sum(root->left));
        int r = max(0, sum(root->right));
        ans = max(ans, l + r + root->data);
        return root->data + max(l, r);
    }
    int findMaxSum(Node *root) {
        ans = INT_MIN;
        sum(root);
        return ans;
    }
};

