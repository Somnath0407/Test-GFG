class Solution {
  public:
    void findInRange(Node *root, vector<int>& ans, int l, int h) {
        if (!root)
            return;

        if (root->data > l)
            findInRange(root->left, ans, l, h);

        if (root->data >= l && root->data <= h)
            ans.push_back(root->data);

        if (root->data < h)
            findInRange(root->right, ans, l, h);
    }

    vector<int> printNearNodes(Node *root, int low, int high) {
        vector<int> ans;
        findInRange(root, ans, low, high);
        return ans;
    }
};
