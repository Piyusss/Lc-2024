using ll=long long;
const ll M=1E9+7;

class Fancy {
public:

    vector<ll>v;
    ll a=0,m=1;

    ll pw(ll x,ll y){
        if(!y) return 1;
        ll h=pw(x,y/2)%M;
        ll r=(h*h)%M;
        
        if(y&1) r=(r*x)%M;
        return r;
    }

    Fancy(){}

    void append(int x){
        ll t=((x-a)%M+M)%M;
        t=(t*pw(m,M-2))%M;
        v.push_back(t);
    }

    void addAll(int x){
        a=(a+x)%M;
    }

    void multAll(int x){
        m=(m*x)%M;
        a=(a*x)%M;
    }

    int getIndex(int i){
        if(i>=v.size()) return -1;
        return (v[i]*m+a)%M;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */