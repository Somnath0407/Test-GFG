/*The Node structure is
class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};*/

bool deadend(Node *root, int lower, int upper) {
    if (root == NULL)
        return false;

    // Leaf node check
    if (root->left == NULL && root->right == NULL) {
        if (root->data - lower == 1 && upper - root->data == 1)
            return true;
        else
            return false;
    }

    // Recursive check in left and right subtrees
    bool left = deadend(root->left, lower, root->data);
    bool right = deadend(root->right, root->data, upper);

    if (left || right)
        return true;
    else
        return false;
}

class Solution {
  public:
    bool isDeadEnd(Node *root) {
        return deadend(root, 0, INT_MAX);
    }
};
