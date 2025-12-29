class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        int i = 0, j = 0, ans = -1;
        while (i < a.size() && j < b.size()) {
            if (a[i] <= b[j]) {
                ans = a[i++];
            }
            else {
                ans = b[j++];
            }
            if (--k == 0){ 
                return ans;
            }
        }
        while (i < a.size()) {
            ans = a[i++];
            if (--k == 0) return ans;
        }

        while (j < b.size()) {
            ans = b[j++];
            if (--k == 0) return ans;
        }
        return ans;
    }
};
