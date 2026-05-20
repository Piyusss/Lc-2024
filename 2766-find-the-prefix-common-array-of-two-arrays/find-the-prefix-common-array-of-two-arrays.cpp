class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a,vector<int>& b) {
        int n=a.size();

        vector<int>f(n+1),r;
        int c=0;

        for(int i=0;i<n;i++){
            f[a[i]]++;
            if(f[a[i]]==2) c++;

            f[b[i]]++;
            if(f[b[i]]==2) c++;

            r.push_back(c);
        }

        return r;
    }
};