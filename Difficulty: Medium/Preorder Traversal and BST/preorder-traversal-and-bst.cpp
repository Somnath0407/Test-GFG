// User function Template for C++

class Solution {
  public:
    int canRepresentBST(int arr[], int N) {
        stack<int>lower,upper;
        lower.push(INT_MIN);
        upper.push(INT_MAX);
        int left,right;
        for(int i=0;i<N;i++){
            if(arr[i]<lower.top())
            return 0;
            
            while(arr[i]>upper.top()){
                upper.pop();
                lower.pop();
            }
            
            left=lower.top();
            right=upper.top();
            upper.pop();
            lower.pop();
            
            // right side
            lower.push(arr[i]);
            upper.push(right);
            
            // left side
            lower.push(left);
            upper.push(arr[i]);
            
        }
        return 1;
        
    }
};