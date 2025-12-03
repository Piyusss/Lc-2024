using ll=long long;

class Solution{
    int f(unordered_map<int,unordered_map<int,int>>&m){
        ll r=0;

        for(auto &a:m){
            ll s=0;
            for(auto &b:a.second)s+=b.second;
            for(auto &b:a.second){
                s-=b.second;
                r+=b.second*s;
            }
        }
        return r;
    }

public:
    int countTrapezoids(vector<vector<int>>& p) {
        unordered_map<int,unordered_map<int,int>>a,b;
        int n=p.size();

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x=p[j][0]-p[i][0],y=p[j][1]-p[i][1];

                if(x<0 || (x==0&&y<0))x=-x,y=-y;

                int g=gcd(x,abs(y));
                int u=x/g,v=y/g;

                int d=u*p[i][1]-v*p[i][0];
                int k1=(u<<12)|(v+2000);

                int k2=(x<<12)|(y+2000);
                a[k1][d]++;
                b[k2][d]++;
            }
        }

        return f(a)-f(b)/2;
    }
};