class Solution {
public:
    struct Node {
        int cnt;
        Node* child[2];
        Node() {
            cnt = 0;
            child[0] = child[1] = nullptr;
        }
    };
    
    Node* root;
    static const int MAXB = 15; 

    void insert(int x) {
        Node* cur = root;
        for (int b = MAXB; b >= 0; --b) {
            int bit = (x >> b) & 1;
            if (!cur->child[bit]) cur->child[bit] = new Node();
            cur = cur->child[bit];
            cur->cnt++;
        }
    }
    
    int query(int x, int k) {
        Node* cur = root;
        int ans = 0;
        for (int b = MAXB; b >= 0 && cur; --b) {
            int xb = (x >> b) & 1;
            int kb = (k >> b) & 1;
            if (kb) {
                if (cur->child[xb]) ans += cur->child[xb]->cnt;
                cur = cur->child[xb ^ 1];
            } else {
                cur = cur->child[xb];
            }
        }
        return ans;
    }
    
    int cntPairs(vector<int>& arr, int k) {
        root = new Node();
        int n = arr.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += query(arr[i], k);
            insert(arr[i]);
        }
        return ans;
    }
};
