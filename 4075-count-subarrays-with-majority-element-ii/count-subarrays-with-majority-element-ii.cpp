class Solution {
public:
    long long countMajoritySubarrays(vector<int>& a,int t) {
        int n=a.size(),p=n;

        vector<int>f(2*n+1);
        f[n]=1;

        long long x=0,r=0;

        for(auto &v:a){
            if(v==t) x+=f[p++];
            else x-=f[--p];

            f[p]++;
            r+=x;
        }

        return r;
    }
};