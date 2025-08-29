class Solution {
  public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int start = mat[0][0], end = mat[n-1][n-1];
        
        while (start < end) {
            int mid = start + (end - start) / 2;
            int count = 0;
            for (int i = 0; i < n; i++) {
                count += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
            }
            if (count < k) start = mid + 1;
            else end = mid;
        }
        
        return start;
    }
};
