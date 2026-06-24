const int M=1E9+7;
int m,s;

vector<int>operator*(vector<int>&a,vector<int>&b){
    vector<int>c(s);

    for(int i=0;i<m;i++) for(int k=0;k<m;k++) if(a[i*m+k]) for(int j=0;j<m;j++) c[i*m+j]=(c[i*m+j]+1LL*a[i*m+k]*b[k*m+j])%M;
    return c;
}

vector<int>f(vector<int>&a,vector<int>&b){
    vector<int>c(s);

    for(int i=0;i<m;i++)
        for(int j=0;j<=i;j++){
            long long x=0;

            for(int k=0;k<m;k++)
                x=(x+1LL*a[i*m+k]*b[j*m+k])%M;

            c[i*m+j]=c[j*m+i]=x;
        }

    return c;
}

vector<int>id(){
    vector<int>r(s);
    for(int i=0;i<m;i++) r[i*m+i]=1;
    return r;
}

vector<int>p(vector<int>a,int e){
    vector<int>r=id();

    while(e){
        if(e&1) r=f(r,a);
        a=f(a,a);
        e>>=1;
    }

    return r;
}

class Solution {
public:
    int zigZagArrays(int n,int l,int r) {
        m=r-l+1;
        s=m*m;

        vector<int>u(s),d(s);
        for(int i=0;i<m;i++) for(int j=i+1;j<m;j++) u[i*m+j]=1;
        for(int i=0;i<m;i++) for(int j=0;j<i;j++) d[i*m+j]=1;

        n--;
        auto x=p(u*d,n>>1);

        if(n&1) x=d*x;
        return 2LL*accumulate(x.begin(),x.end(),0LL)%M;
    }
};