class Solution {
public:
    int findWays(int n) {
        if (n % 2 == 1) return 0;      // odd length can't be valid
        int m = n / 2;                 // number of pairs

        long long C[21] = {0};
        C[0] = 1;

        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < i; j++) {
                C[i] += C[j] * C[i - 1 - j];
            }
        }
        return (int)C[m];
    }
};
