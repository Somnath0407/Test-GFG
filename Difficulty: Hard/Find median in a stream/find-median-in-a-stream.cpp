
class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        priority_queue<int> leftmaxheap;  
        priority_queue<int, vector<int>, greater<int>> rightminheap;  
        vector<double> result;

        for (int x : arr) {
            if (leftmaxheap.empty() || x <= leftmaxheap.top()) {
                leftmaxheap.push(x);
            } else {
                rightminheap.push(x);
            }

            // balance heaps
            if (rightminheap.size() > leftmaxheap.size()) {
                leftmaxheap.push(rightminheap.top());
                rightminheap.pop();
            } else if (leftmaxheap.size() > rightminheap.size() + 1) {
                rightminheap.push(leftmaxheap.top());
                leftmaxheap.pop();
            }

            // get median
            if (leftmaxheap.size() > rightminheap.size()) {
                result.push_back(leftmaxheap.top());
            } else {
                result.push_back((leftmaxheap.top() + rightminheap.top()) / 2.0);
            }
        }
        return result;
    }
};
