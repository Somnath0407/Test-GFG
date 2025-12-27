class Solution {
  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        vector<int> v;
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[i].size(); j++){
                v.push_back(mat[i][j]);
            }
        }
        sort(v.begin(), v.end());
        return v[k-1];
    }
};
