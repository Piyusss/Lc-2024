using ll=long long;

class Router {
    int sz;
    unordered_map<ll,array<int,3>> m;
    unordered_map<int,vector<int>> c;
    queue<ll> q;
    
    static ll enc(int s,int d,int t) {
        return ((ll)s<<40)|((ll)d<<20)|(ll)t;
    }

public:
    Router(int x){
        sz=x;
        m.reserve(max(1,x*2));
    }

    bool addPacket(int s,int d,int t) {
        ll k=enc(s,d,t);
        if(m.count(k))return 0;

        if((int)m.size()>=sz)forwardPacket();
        m[k]={s,d,t};
        q.push(k);

        auto &v=c[d];
        auto it=lower_bound(v.begin(),v.end(),t);

        v.insert(it,t);
        return 1;
    }

    vector<int> forwardPacket() {
        if(m.empty())return {};
        ll k=q.front();q.pop();
        auto it=m.find(k);

        if(it==m.end())return {};
        auto p=it->second;
        m.erase(it);

        int d=p[1],t=p[2];
        auto &v=c[d];
        auto itv=lower_bound(v.begin(),v.end(),t);

        if(itv!=v.end()&&*itv==t)v.erase(itv);
        return {p[0],p[1],p[2]};
    }

    int getCount(int d,int l,int r) {
        if(!c.count(d))return 0;
        auto &v=c[d];

        auto L=lower_bound(v.begin(),v.end(),l);
        auto R=upper_bound(v.begin(),v.end(),r);

        return R-L;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */