class Solution {
public:
    int countSetBits(int n) {
        if(n == 0) return 0;
        int x = log2(n);
        int upto2x = x * (1 << (x - 1));
        int msb = n - (1 << x) + 1;
        int rest = n - (1 << x);
        return upto2x + msb + countSetBits(rest);
    }
};
