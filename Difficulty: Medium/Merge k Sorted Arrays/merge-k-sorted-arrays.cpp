class Solution {
  public:
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        vector<int> result;
        for (int i = 0; i < K; i++) {
            for (int j = 0; j < K; j++) {
                result.push_back(arr[i][j]);
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
};
