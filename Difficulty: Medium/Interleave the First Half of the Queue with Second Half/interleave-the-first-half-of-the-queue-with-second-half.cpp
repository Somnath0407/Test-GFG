class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
         int n = q.size();
        if (n % 2) return;
        queue<int> firstHalf;
        for(int i=0;i<n/2;i++){
            firstHalf.push(q.front());
            q.pop();
        }
        while(!firstHalf.empty()){
            q.push(firstHalf.front());
            firstHalf.pop();
            q.push(q.front());
            q.pop();
        }
    }
};