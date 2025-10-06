class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int n = arr.size();
        if (n <= 2) return 0;
        int maxheight = arr[0];
        int index = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i] > maxheight) {
                maxheight = arr[i];
                index = i;
            }
        }
        int water = 0;
        int maxleft = arr[0];
        int maxright = arr[n - 1];
        for (int i = 0; i < index; i++) {
            if (maxleft > arr[i])
                water += maxleft - arr[i];
            else
                maxleft = arr[i];
        }
        for (int i = n - 1; i > index; i--) {
            if (maxright > arr[i])
                water += maxright - arr[i];
            else
                maxright = arr[i];
        }
        return water;
    }
};