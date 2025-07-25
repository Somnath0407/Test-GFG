class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        int totalsum = 0;
        int maxnormal = arr[0];
        int minnormal = arr[0];
        int currmax = arr[0];
        int currmin = arr[0];

        for(int i = 1; i < arr.size(); i++) {
            currmax = max(arr[i], currmax + arr[i]);
            maxnormal = max(maxnormal, currmax);

            currmin = min(arr[i], currmin + arr[i]);
            minnormal = min(minnormal, currmin);
        }

        for(int i = 0; i < arr.size(); i++) {
            totalsum += arr[i];
        }

        if(totalsum == minnormal)
            return maxnormal;

        return max(maxnormal, totalsum - minnormal);
    }
};
