class Solution {
  public:
    vector<int> kSmallestElements(vector<int>& arr, int k) {
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());
        unordered_map<int,int> freq;
        for(int i = 0; i < k; i++)
            freq[temp[i]]++;
        vector<int> ans;
        for(int x : arr) {
            if(freq[x] > 0) {
                ans.push_back(x);
                freq[x]--;
            }
            if(ans.size() == k) break;
        }
        return ans;
    }
};
 