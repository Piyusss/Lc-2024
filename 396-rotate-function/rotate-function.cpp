using ll=long long;

class Solution {
public:
    int maxRotateFunction(vector<int>& a) {
        int n=a.size();

        ll s=0,c=0;
        for(int i=0;i<n;i++){
            s+=a[i];
            c+=1LL*i*a[i];
        }

        ll r=c;
        for(int k=1;k<n;k++){
            c=c+s-1LL*n*a[n-k];
            r=max(r,c);
        }
        
        return r;
    }
};