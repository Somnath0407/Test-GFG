class Solution {
  public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) return 0;
        int hold = -arr[0];
        int sold = 0;
        int cool = 0;
        for (int i = 1; i < n; i++) {
            int prevSold = sold;
            sold = hold + arr[i];
            hold = max(hold, cool - arr[i]);
            cool = max(cool, prevSold);
        }
        return max(sold, cool);
    }
};
