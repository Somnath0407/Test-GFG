class Solution {
  public:
    string minWindow(string& s1, string& s2) {
        int n = s1.size();
        int m = s2.size();
        string ans="";
        int minLen = 1e9;
        for(int i=0;i<n;i++){
            int j=0;
            int k=i;
            while (k < n && j < m) {
                if (s1[k] == s2[j]) {
                    j++;
                }
                k++;
            }
            if(j<m) continue;
            int end=k-1;
            j=m-1;
            k=end;
            while(k>=i){
                if(s1[k]==s2[j]) {
                    j--;
                }
                if(j < 0) break;
                k--;
            }
            int len = end - k + 1;
            if (len < minLen) {
                minLen = len;
                ans = s1.substr(k, len);
            }
        }
        return ans;
    }
};
