const int M=1E9+7;

class Solution {
public:

    vector<int> sumAndMultiply(string s,vector<vector<int>>& q) {
        int n=s.size();

        vector<int>p(n+1),x(n+1),l(n+1);

        for(int i=0;i<n;i++){
            int d=s[i]-'0';

            p[i+1]=p[i]+d;

            if(d){
                x[i+1]=(x[i]*10LL+d)%M;
                l[i+1]=l[i]+1;
            }
            else{
                x[i+1]=x[i];
                l[i+1]=l[i];
            }
        }

        vector<int>t(l[n]+1);
        t[0]=1;

        for(int i=1;i<=l[n];i++) t[i]=t[i-1]*10LL%M;
        vector<int>r;

        for(auto &v:q){
            int a=v[0],b=v[1]+1;
            int s=p[b]-p[a];
            long long y=(x[b]-1LL*x[a]*t[l[b]-l[a]]%M+M)%M;
            r.push_back(y*s%M);
        }

        return r;
    }
};