class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int> p;

        for(int i = 0; i < arr.size(); i++) {
            if(p.size() < k) {
                p.push(arr[i]);
            } else if(arr[i] < p.top()) {
                p.pop();
                p.push(arr[i]);
            }
        }

        return p.top();
    }
};
