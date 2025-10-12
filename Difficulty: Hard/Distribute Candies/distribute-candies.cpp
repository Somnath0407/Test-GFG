/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
public:
    int ans;
    int dfs(Node* root){
        if(!root) return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        ans += abs(l) + abs(r);
        return root->data + l + r - 1;
    }
    int distCandy(Node* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
};
