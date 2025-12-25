class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int l = 0, r = m - 1;
        while(l <= r){
            int mid = (l + r) >> 1;
            int row = 0;
            for(int i = 0; i < n; i++)
                if(mat[i][mid] > mat[row][mid])
                    row = i;  
            int val = mat[row][mid];
            int left  = (mid > 0) ? mat[row][mid-1] : INT_MIN;
            int right = (mid < m-1) ? mat[row][mid+1] : INT_MIN;
            if(val >= left && val >= right)
                return {row, mid};
            if(right > val)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return {-1, -1};
    }
};
