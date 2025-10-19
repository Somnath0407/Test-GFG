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
    void inorder(Node* root, vector<int>& v) {
        if (!root) return;
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }

    vector<int> getKClosest(Node* root, int target, int k) {
        vector<int> v;
        inorder(root, v);
        
        sort(v.begin(), v.end(), [&](int a, int b) {
            int da = abs(a - target);
            int db = abs(b - target);
            if (da != db) return da < db; 
            return a < b;                
        });

        v.resize(k); 
        return v;
    }
};
