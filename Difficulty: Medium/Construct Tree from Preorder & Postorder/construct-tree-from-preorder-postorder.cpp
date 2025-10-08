/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    Node* construct(vector<int>& pre, vector<int>& post, int& preIndex, int l, int r, int n) {
        if (preIndex >= n || l > r)
            return NULL;
        Node* root = new Node(pre[preIndex++]);
        if (l == r || preIndex >= n)
            return root;
        int i;
        for (i = l; i <= r; i++)
            if (post[i] == pre[preIndex])
                break;
        if (i <= r) {
            root->left = construct(pre, post, preIndex, l, i, n);
            root->right = construct(pre, post, preIndex, i + 1, r - 1, n);
        }
        return root;
    }
    Node* constructTree(vector<int>& pre, vector<int>& post) {
        int preIndex = 0;
        int n = pre.size();
        return construct(pre, post, preIndex, 0, n - 1, n);
    }
};
