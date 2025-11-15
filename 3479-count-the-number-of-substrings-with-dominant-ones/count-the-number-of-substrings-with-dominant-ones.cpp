class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size(),res=0;
        vector<int>z;

        for(int i=0;i<n;i++)if(s[i]=='0')z.push_back(i);
        z.push_back(n);

        int lim=sqrt(n);
        for(int i=0;i<n;i++){
            int pos=lower_bound(z.begin(),z.end(),i)-z.begin();

            if(z[pos]<i)continue;
            int cnt=0,last=i;

            for(int j=pos;j<z.size() && j<=pos+lim;j++){
                int ones=cnt*cnt;
                int idx=max(i+cnt+ones-1,last);

                if(idx<z[j])res+=z[j]-idx;
                last=z[j];
                cnt++;
            }
        }

        return res;
    }
};