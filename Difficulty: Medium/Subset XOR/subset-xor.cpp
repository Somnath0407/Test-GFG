class Solution {
public:
    vector<int> subsetXOR(int n) {
        int T = 0;
        for (int i = 1; i <= n; i++) T ^= i;
        if (T == n) {
            vector<int> res(n);
            for (int i = 1; i <= n; i++) res[i-1] = i;
            return res;
        }
        int miss = T ^ n;
        if (miss >= 1 && miss <= n) {
            vector<int> res;
            for (int i = 1; i <= n; i++)
                if (i != miss) res.push_back(i);
            return res;
        }

        int k = T ^ n;
        int a = 1, b = 1 ^ k;
        vector<int> res;
        for (int i = 1; i <= n; i++)
            if (i != a && i != b) res.push_back(i);
        return res;
    }
};
