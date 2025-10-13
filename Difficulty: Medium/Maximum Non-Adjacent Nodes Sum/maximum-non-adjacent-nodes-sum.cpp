/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
public:
    pair<long long, long long> dfs(Node* root) {
        if (!root) return {0, 0};
        pair<long long, long long> left = dfs(root->left);
        pair<long long, long long> right = dfs(root->right);
        long long include = root->data + left.second + right.second;
        long long exclude = max(left.first, left.second) + max(right.first, right.second);
        return {include, exclude};
    }
    int getMaxSum(Node* root) {
        pair<long long, long long> res = dfs(root);
        return max(res.first, res.second);
    }
};
