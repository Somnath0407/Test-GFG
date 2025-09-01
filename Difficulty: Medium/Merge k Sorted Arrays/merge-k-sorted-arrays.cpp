class Solution {
  public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<pair<int, pair<int,int>>>
        > pq;
        for (int i = 0; i < K; i++) {
            if (!arr[i].empty()) {
                pq.push({arr[i][0], {i, 0}});
            }
        }

        vector<int> ans;
        while (!pq.empty()) {
            auto element = pq.top();
            pq.pop();

            int val = element.first;
            int row = element.second.first;
            int col = element.second.second;

            ans.push_back(val);

            if (col + 1 < arr[row].size()) {
                pq.push({arr[row][col + 1], {row, col + 1}});
            }
        }
        return ans;
    }
};
