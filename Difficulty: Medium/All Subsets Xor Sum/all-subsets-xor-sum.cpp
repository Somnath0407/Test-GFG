class Solution {
public:
    int subsetXORSum(vector<int>& arr) {
        int n = arr.size(), OR = 0;
        for(int x : arr) OR |= x;
        return OR * (1 << (n - 1));
    }
};
