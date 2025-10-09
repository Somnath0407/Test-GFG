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
    vector<int> postOrder(Node* root) {
        stack<Node *>s;
        s.push(root);
        vector<int>ans;
        while(!s.empty()){
            Node *temp=s.top();
            s.pop();
            ans.push_back(temp->data);
            if(temp->left){
            s.push(temp->left);
            }
            if(temp->right){
                s.push(temp->right);
            }
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};