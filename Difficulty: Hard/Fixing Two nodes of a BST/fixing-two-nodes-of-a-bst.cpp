/*
class Node
{
    public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void correctBST(Node* root) {
        Node *first = NULL, *second = NULL;
        Node *last = NULL, *present = NULL;
        Node *curr = NULL;

        Node* temp = root;  // We'll traverse using this pointer

        while (temp) {
            if (!temp->left) {
                last = present;
                present = temp;
                if (last && last->data > present->data) {
                    if (!first)
                        first = last;
                    second = present;
                }
                temp = temp->right;
            } else {
                curr = temp->left;
                while (curr->right && curr->right != temp) {
                    curr = curr->right;
                }
                if (!curr->right) {
                    curr->right = temp;
                    temp = temp->left;
                } else {
                    curr->right = NULL;
                    last = present;
                    present = temp;
                    if (last && last->data > present->data) {
                        if (!first)
                            first = last;
                        second = present;
                    }
                    temp = temp->right;
                }
            }
        }

        // Swap the values of the misplaced nodes
        if (first && second) {
            swap(first->data, second->data);
        }
    }
};
