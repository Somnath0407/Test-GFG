class Solution {
  public:
    bool canServe(vector<int> &arr) {
        int count=0;
        int ten=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==5){
                count++;
            }
            else if (arr[i] == 10) {
                if (count >= 1) {
                    count--;
                    ten++;
                } else {
                    return false;
                }
            }
            else if (arr[i] == 20) {
                if (ten>=1 && count>=1) {
                    count--;
                    ten--;
                }
                else if(count >= 3 ){
                    count-=3;
                }
                else {
                    return false;
                }
            }
            else{
                return false;
            }
        }
        if(count<0){
            return false;
        }
        else{
            return true;
        }
    }
};