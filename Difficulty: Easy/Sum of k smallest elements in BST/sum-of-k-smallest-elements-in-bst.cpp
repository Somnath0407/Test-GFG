// User function Template for C++

/*
struct Node {
    int data;
    Node* right;
    Node* left;

    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
*/

// Function to find ceil of a given input in BST. If input is more
// than the max key in BST, return -1
void inorder(Node* root, int& k, int& sum, int& count) {
    if (!root || count >= k)
        return;

    inorder(root->left, k, sum, count);
    
    if (count < k) {
        sum += root->data;
        count++;
    }

    inorder(root->right, k, sum, count);
}

int sum(Node* root, int k) {
    int totalSum = 0, count = 0;
    inorder(root, k, totalSum, count);
    return totalSum;
}