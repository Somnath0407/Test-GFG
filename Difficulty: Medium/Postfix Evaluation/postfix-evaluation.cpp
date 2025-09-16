class Solution {
  public:
    int evaluatePostfix(vector<string>& arr) {
        stack<long long>ss;
        for(int i=0;i<arr.size();i++){
            string s=arr[i];
            if(s == "+" || s == "-" || s == "*" || s == "/" || s == "^"){
                long long b=ss.top();
                ss.pop();
                long long a=ss.top();
                ss.pop();
                long long res=0;
                if (s == "+") res = a + b;
                else if (s == "-") res = a - b;
                else if (s == "*") res = a * b;
                else if (s== "/"){
                     if (a * b < 0 && a % b != 0)
                        res = a / b - 1;  
                    else
                        res = a / b;
                }
                else if (s == "^") res = pow(a, b);
                ss.push(res);
            } 
            else {
                ss.push(stoll(s));
            }
        }
        return ss.top();
    }
};