class Solution {
  public:
    void sortIt(vector<int>& arr) {
        vector<int> v;
        vector<int> c;
        vector<int> d;
        for(int i=0;i<arr.size();i++){
            if(arr[i]%2==0){
                v.push_back(arr[i]);
            }
            else{
                c.push_back(arr[i]);
            }
        }
        sort(c.begin(),c.end(),greater<int>());
        sort(v.begin(),v.end());
        arr.clear();
        arr.insert(arr.end(), c.begin(), c.end());
        arr.insert(arr.end(), v.begin(), v.end());
    }
};