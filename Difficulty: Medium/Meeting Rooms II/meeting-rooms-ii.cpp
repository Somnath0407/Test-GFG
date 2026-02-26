class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        int n=start.size();
        int m=end.size();
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int res=0,room=0;
        int i=0,j=0;
        while(i<n && j<m){
            if(start[i]<end[j]){
                room++;
                res=max(res,room);
                i++;
            }
            else{
                room--;
                j++;
            }
        }
        return res;
    }
};
