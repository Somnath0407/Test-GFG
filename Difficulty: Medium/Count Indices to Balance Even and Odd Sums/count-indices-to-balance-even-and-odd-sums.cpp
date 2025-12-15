class Solution {
public:
    int cntWays(vector<int>& arr) {
        int n = arr.size();
        int totalEven = 0, totalOdd = 0;
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) totalEven += arr[i];
            else totalOdd += arr[i];
        }
        int prefEven = 0, prefOdd = 0;
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) totalEven -= arr[i];
            else totalOdd -= arr[i];
            int newEven = prefEven + totalOdd;
            int newOdd  = prefOdd + totalEven;
            if(newEven == newOdd) count++;
            if(i % 2 == 0) prefEven += arr[i];
            else prefOdd += arr[i];
        }
        return count;
    }
};
