class Solution {
  public:
    int minCost(vector<int>& height) {
        int n = height.size();
        int prev = 0, prev2 = 0;
        for (int i = 1; i < n; i++) {
            int one = prev + abs(height[i] - height[i-1]);
            int two = INT_MAX;
            if (i > 1)
                two = prev2 + abs(height[i] - height[i-2]);
            int curr = min(one, two);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};
