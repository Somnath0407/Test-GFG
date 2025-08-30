class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n=mat.size();
        int i=0,j=n-1;
        while(i<j){
            if(mat[i][j]==1){
                i++;
            }
            else{
                j--;
            }
        }
        int ce=i;
        for (int k = 0; k < n; k++) {
            if (k != ce) {
                if (mat[ce][k] == 1 || mat[k][ce] == 0)
                    return -1;
            }
        }
        return ce;
        
    }
};