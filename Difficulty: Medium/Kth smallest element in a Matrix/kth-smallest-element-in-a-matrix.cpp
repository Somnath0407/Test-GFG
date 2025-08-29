class Solution {
  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        int n = mat.size();
        vector<pair<int,pair<int,int>>> temp;
        for(int i=0; i<n; i++) {
            temp.push_back(make_pair(mat[i][0],make_pair(i,0)));
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> p(temp.begin(),temp.end()); 
        int ans;
        pair<int,pair<int,int>> element;
        int i,j;

        while(k--){
            element = p.top();
            p.pop();
            ans = element.first;
            i = element.second.first;
            j = element.second.second;
            if(j+1 < mat[i].size()){
                p.push(make_pair(mat[i][j+1],make_pair(i,j+1)));
            }
        }
        return ans;
    }
};
