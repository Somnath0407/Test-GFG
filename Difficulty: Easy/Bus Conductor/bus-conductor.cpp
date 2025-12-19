class Solution {
  public:
    int findMoves(vector<int>& chairs, vector<int>& passengers) {
        sort(chairs.begin(),chairs.end());
        sort(passengers.begin(),passengers.end());
        int first=chairs[0],second=passengers[0];
        int sum=0;
        for(int i=0;i<chairs.size();i++){
            sum=sum+abs(chairs[i]-passengers[i]);
        }
        return sum;
    }
};