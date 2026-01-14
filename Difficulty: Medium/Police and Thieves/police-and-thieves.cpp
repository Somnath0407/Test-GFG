class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        int n=arr.size();
        int police=0;
        int thief=0;
        int count =0;
        while(police<n && arr[police]!='P') police++;
        while(thief<n && arr[thief]!='T') thief++;
        while(police<n && thief<n){
            if(abs(police-thief)<=k){
                count++;
                police++;
                thief++;
            }
            else if(police<thief) police++;
            else if(police>thief) thief++;
            while(police<n && arr[police]!='P') police++;
            while(thief<n && arr[thief]!='T') thief++;
        }
        return count;
    }
};