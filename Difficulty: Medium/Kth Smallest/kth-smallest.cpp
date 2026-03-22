class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        priority_queue<int>pq;
        for(int i=0;i<k;i++){
            pq.push(arr[i]);
        }
        for(int i=k;i<arr.size();i++){
            if(pq.top()<=arr[i]) continue;
            else {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        return pq.top();
    }
};