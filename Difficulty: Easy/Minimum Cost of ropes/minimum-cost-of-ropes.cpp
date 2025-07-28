class Solution {
  public:
    int minCost(vector<int>& arr) {
        // Min heap
        priority_queue<long long, vector<long long>, greater<long long>> p;

        for (int i = 0; i < arr.size(); i++)
            p.push(arr[i]);

        long long cost = 0;

        while (p.size() > 1) {
            long long rope1 = p.top(); p.pop();
            long long rope2 = p.top(); p.pop();
            long long sum = rope1 + rope2;
            cost += sum;
            p.push(sum);
        }

        return (int)cost;
    }
};
