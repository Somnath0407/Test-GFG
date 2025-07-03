class Solution {
  public:
  class box{
    public:
    bool bst;
    int min, max;
    int size;

    box(bool isBst, int sz, int mn, int mx) {
        bst = isBst;
        size = sz;
        min = mn;
        max = mx;
    }
  };

  box* find(Node *root, int &totalsize) {
    if (!root) return new box(true, 0, INT_MAX, INT_MIN);

    box *left = find(root->left, totalsize);
    box *right = find(root->right, totalsize);

    if (left->bst && right->bst && root->data > left->max && root->data < right->min) {
        int sz = 1 + left->size + right->size;
        totalsize = max(totalsize, sz);
        return new box(true, sz, min(root->data, left->min), max(root->data, right->max));
    }

    return new box(false, 0, 0, 0);
  }

  int largestBst(Node *root) {
    int totalsize = 0;
    find(root, totalsize);
    return totalsize;
  }
};
