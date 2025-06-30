class Solution {
  public:
    void inorder(Node* root, vector<int>& v) {
        if (!root) return;
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }

    vector<int> findCommon(Node *r1, Node *r2) {
        vector<int> v1, v2, res;
        
        inorder(r1, v1);
        inorder(r2, v2);
        
        int i = 0, j = 0;
        while (i < v1.size() && j < v2.size()) {
            if (v1[i] == v2[j]) {
                res.push_back(v1[i]);
                i++;
                j++;
            } else if (v1[i] < v2[j]) {
                i++;
            } else {
                j++;
            }
        }
        
        return res;
    }
};
