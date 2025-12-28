class Solution {
  public:
  bool ispossible(long long mid,long long n,vector<int>& ranks){
      long long donuts=0;
      for(int i=0;i<ranks.size();i++){
          long long time=0;
          long long step=ranks[i];
          while(time+step<=mid){
              time+=step;
              donuts++;
              step+=ranks[i];
              if(donuts >= n)   
                    return true;
          }
      }
      return donuts >= n;
  }
    int minTime(vector<int>& ranks, int n) {
        int l=ranks.size();
        sort(ranks.begin(),ranks.end());
        long long low=0;
        long long h=10000000000;
        long long time=0;
        while(low<=h){
            long long mid=low+(h-low)/2;
            if(ispossible(mid,n,ranks)){
                time=mid;
                h=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return time;
    }
};