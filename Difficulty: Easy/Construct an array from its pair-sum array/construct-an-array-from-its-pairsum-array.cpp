class Solution {
  public:
    vector<int> constructArr(vector<int>& arr) {
        using ll = long long;
        int m = arr.size();
        if(m==0) return {};
        int n = (int)((1 + sqrt(1 + 8.0*m)) / 2);
        if(n*(n-1)/2 != m) return {};
        vector<ll> res(n,0);
        if(n==1) return {};
        if(n==2){
            ll s01 = arr[0];
            res[0] = s01/2;
            res[1] = s01 - res[0];
            return vector<int>{(int)res[0], (int)res[1]};
        }
        ll s01 = arr[0], s02 = arr[1], s12 = arr[n-1];
        ll t = s01 + s02 - s12;
        if(t < 0 || (t & 1)) return {};
        res[0] = t/2;
        res[1] = s01 - res[0];
        res[2] = s02 - res[0];
        for(int k=3;k<n;++k) res[k] = (ll)arr[k-1] - res[0];
        vector<ll> build;
        build.reserve(m);
        for(int i=0;i<n;++i)
            for(int j=i+1;j<n;++j)
                build.push_back(res[i]+res[j]);
        for(int i=0;i<m;++i) if(build[i] != (ll)arr[i]) return {};
        vector<int> out(n);
        for(int i=0;i<n;++i) out[i] = (int)res[i];
        return out;
    }
};
