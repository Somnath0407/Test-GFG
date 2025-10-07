/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    void findWidth(Node* root, int pos, int &l, int &r) {
        if (!root) return;
        l = min(l, pos);
        r = max(r, pos);
        findWidth(root->left, pos - 1, l, r);
        findWidth(root->right, pos + 1, l, r);
    }
    void fillBottom(Node* root, int pos, int depth, vector<int>& ans, vector<int>& level) {
        if (!root) return;
        if (depth >= level[pos]) { 
            ans[pos] = root->data;
            level[pos] = depth;
        }
        fillBottom(root->left, pos - 1, depth + 1, ans, level);
        fillBottom(root->right, pos + 1, depth + 1, ans, level);
    }
    vector<int> bottomView(Node *root) {
        if (!root) return {};
        int l = 0, r = 0;
        findWidth(root, 0, l, r);
        int width = r - l + 1;
        vector<int> ans(width);
        vector<int> level(width, -1);
        
        fillBottom(root, -l, 0, ans, level);
        return ans;
    }
};
