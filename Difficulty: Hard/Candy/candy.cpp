class Solution {
  public:
    int minCandy(vector<int> &arr) {
        int n=arr.size();
        if (n == 0) return 0;
        vector<int> c(n, 1);
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1]) c[i] = c[i - 1] + 1;
        }
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] > arr[i + 1]) c[i] = max(c[i], c[i + 1] + 1);
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=c[i];
        }
        return sum;
    }
};
