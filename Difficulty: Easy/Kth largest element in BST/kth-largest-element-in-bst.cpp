/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'
class Solution {
  public:
    void reverseInorder(Node* root, int& k, int& count, int& result) {
        if (!root || count >= k)
            return;

        reverseInorder(root->right, k, count, result);

        count++;
        if (count == k) {
            result = root->data;
            return;
        }

        reverseInorder(root->left, k, count, result);
    }

    int kthLargest(Node *root, int k) {
        int count = 0;
        int result = -1;
        reverseInorder(root, k, count, result);
        return result;
    }
};
