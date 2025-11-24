class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& a) {
        int r=0,n=a.size();

        vector<bool>v(n);
        for(int i=0;i<n;i++){
            r=((r<<1)+a[i])%5;
            v[i]=(r==0);
        }

        return v;
    }
};