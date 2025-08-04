class Solution {
  public:
    vector<int> kthLargest(int k, int arr[], int n) {
        vector<int> result;
        priority_queue<int, vector<int>, greater<int>> pq; 

        for (int i = 0; i < n; i++) {
            pq.push(arr[i]);
            if (pq.size() > k) {
                pq.pop(); 
            }
            if (i >= k - 1) {
                result.push_back(pq.top()); 
            } else {
                result.push_back(-1); 
            }
        }

        return result;
    }
};