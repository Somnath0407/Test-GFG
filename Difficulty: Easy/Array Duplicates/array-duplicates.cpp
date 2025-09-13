class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<int> ans;
        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i] == arr[i + 1]) {
                ans.push_back(arr[i]);
                while (i < arr.size() - 1 && arr[i] == arr[i + 1]) i++;
            }
        }
        return ans;
    }
};
