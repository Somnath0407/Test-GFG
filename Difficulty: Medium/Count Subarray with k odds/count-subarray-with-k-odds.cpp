class Solution {
  public:
    int countSubarrays(vector<int>& arr, int k) {
        unordered_map<int,int> m;
        int oddCount = 0, ans = 0;

        m[0] = 1;

        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] % 2 != 0)
                oddCount++;

            if(m.find(oddCount - k) != m.end())
                ans += m[oddCount - k];

            m[oddCount]++;
        }
        return ans;
    }
};
