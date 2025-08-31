

class Solution {
  public:
    int maxWater(vector<int> &arr) {
        int n = arr.size();
        int left = 0, right = n - 1;
        int maxtotalarea = 0;
        while (left < right) {
            int width = right - left;
            int height = min(arr[left], arr[right]);
            maxtotalarea = max(maxtotalarea, width * height);
            if (arr[left] < arr[right]) 
                left++;
            else 
                right--;
        }
        return maxtotalarea;
    }
};
