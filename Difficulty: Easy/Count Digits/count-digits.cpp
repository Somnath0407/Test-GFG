class Solution {
  public:
    int evenlyDivides(int n) {
        int x = n, find = 0;
        while (x > 0) {
            int d = x % 10;
            if (d != 0 && n % d == 0) find++;
            x /= 10;
        }
        return find;
    }
};
