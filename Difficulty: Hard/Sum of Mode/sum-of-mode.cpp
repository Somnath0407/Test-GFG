class Solution {
public:
    long long sumOfModes(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int,int> freq; 
        map<int, set<int>> bucket;   
        long long ans = 0;

        auto add = [&](int x) {
            int old = freq[x]++;
            if (old > 0) {
                bucket[old].erase(x);
                if (bucket[old].empty()) bucket.erase(old);
            }
            bucket[old+1].insert(x);
        };

        auto remove = [&](int x) {
            int old = freq[x]--;
            bucket[old].erase(x);
            if (bucket[old].empty()) bucket.erase(old);
            if (old-1 > 0) bucket[old-1].insert(x);
            if (freq[x] == 0) freq.erase(x);
        };

        for (int i = 0; i < k; i++) add(arr[i]);
        ans += *bucket.rbegin()->second.begin();

        for (int i = k; i < n; i++) {
            add(arr[i]);
            remove(arr[i-k]);
            ans += *bucket.rbegin()->second.begin();
        }

        return ans;
    }
};