/*struct Node
{
    int data;
    Node *left, *right;
};*/



Node* bstpostorder(vector<int>& postorder, int &index, int lower, int upper) {
    if (index < 0 || postorder[index] < lower || postorder[index] > upper) {
        return NULL;
    }

    int val = postorder[index--];
    Node* root = new Node(val);

    root->right = bstpostorder(postorder, index, val, upper);
    root->left = bstpostorder(postorder, index, lower, val);

    return root;
}

Node* constructTree(int post[], int size) {
    vector<int> postorder(post, post + size);  // convert array to vector
    int index = size - 1;
    return bstpostorder(postorder, index, INT_MIN, INT_MAX);
}
