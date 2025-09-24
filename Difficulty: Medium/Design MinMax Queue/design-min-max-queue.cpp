class SpecialQueue {

  public:
    queue<int> q;
    deque<int> minq, maxq;

    void enqueue(int x) {
        q.push(x);
        while(!minq.empty() && minq.back() > x){
            minq.pop_back();
        } 
        minq.push_back(x);
        while(!maxq.empty() && maxq.back() < x) {
            maxq.pop_back();
        }
        maxq.push_back(x);
        
    }

    void dequeue() {
        int data = q.front();
        q.pop();
        if(data == minq.front()){
           minq.pop_front(); 
        } 
        if(data == maxq.front()) {
            maxq.pop_front();
        }
    }

    int getFront() {
        return q.front();
    }

    int getMin() {
        return minq.front();
    }

    int getMax() {
       return maxq.front();
    }
};