class Solution {
public:
    int minMen(vector<int>& arr) {
        int n = (int)arr.size();
        vector<int> best(n, -1);
        for (int i = 0; i < n; i++) {
            if (arr[i] == -1) continue;
            int L = max(0, i - arr[i]);
            int R = min(n - 1, i + arr[i]);
            best[L] = max(best[L], R);
        }
        int workers = 0;
        int currEnd = -1;
        int far = -1;
        for (int i = 0; i < n; i++) {
            if (best[i] != -1) far = max(far, best[i]);
            if (i > far) return -1;      
            if (i > currEnd) {          
                workers++;
                currEnd = far;
                if (currEnd >= n - 1) return workers;
            }
        }

        return (currEnd >= n - 1) ? workers : -1;
    }
};
