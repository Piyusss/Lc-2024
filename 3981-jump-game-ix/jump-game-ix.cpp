struct T{
    int n;
    const int I=2e9;
    vector<pair<int,int>>t1,t2;

    T(const vector<int>& a) {
        n = a.size();
        t1.resize(4 * n);
        t2.resize(4 * n);
        b(1, 0, n - 1, a);
    }

    void b(int p, int l, int r, const vector<int>& a) {
        if (l == r) {
            t1[p] = {a[l], l};
            t2[p] = {a[l], l};
            return;
        }
        int m = l + (r - l) / 2;
        b(p * 2, l, m, a);
        b(p * 2 + 1, m + 1, r, a);
        t1[p] = min(t1[p * 2], t1[p * 2 + 1]);
        t2[p] = max(t2[p * 2], t2[p * 2 + 1]);
    }

    void z_h(int p, int l, int r, int i) {
        if (l == r) {
            t1[p] = {I, i};
            t2[p] = {-I, i};
            return;
        }
        int m = l + (r - l) / 2;
        if (i <= m) z_h(p * 2, l, m, i);
        else z_h(p * 2 + 1, m + 1, r, i);
        t1[p] = min(t1[p * 2], t1[p * 2 + 1]);
        t2[p] = max(t2[p * 2], t2[p * 2 + 1]);
    }

    void z(int i) {
        z_h(1, 0, n - 1, i);
    }

    int q1_h(int p, int l, int r, int ql, int qr, int x) {
        if (ql > r || qr < l || t1[p].first >= x) return -1;
        if (l == r) return l;
        int m = l + (r - l) / 2;
        int t = q1_h(p * 2, l, m, ql, qr, x);
        if (t != -1) return t;
        return q1_h(p * 2 + 1, m + 1, r, ql, qr, x);
    }

    int q1(int ql, int qr, int x) {
        return q1_h(1, 0, n - 1, ql, qr, x);
    }

    int q2_h(int p, int l, int r, int ql, int qr, int x) {
        if (ql > r || qr < l || t2[p].first <= x) return -1;
        if (l == r) return l;
        int m = l + (r - l) / 2;
        int t = q2_h(p * 2, l, m, ql, qr, x);
        if (t != -1) return t;
        return q2_h(p * 2 + 1, m + 1, r, ql, qr, x);
    }

    int q2(int ql, int qr, int x) {
        return q2_h(1, 0, n - 1, ql, qr, x);
    }
};


class Solution {
public:
    vector<int> maxValue(vector<int>& a) {
        int n=a.size();
        if(n==0) return {};

        T s(a);
        vector<bool>v(n,0);
        vector<int>o(n);

        for(int i=0;i<n;i++){
            if(v[i]) continue;

            vector<int>c;
            deque<int>q;

            q.push_back(i);

            v[i]=1;
            s.z(i);

            c.push_back(i);
            int x=a[i];

            while(!q.empty()){
                int u=q.front();
                q.pop_front();

                while(u+1<n){
                    int p=s.q1(u+1,n-1,a[u]);
                    if(p == -1)break;
                    v[p]=1;
                    s.z(p);
                    q.push_back(p);
                    c.push_back(p);
                    x=max(x,a[p]);
                }

                while(u-1>=0){
                    int p=s.q2(0,u-1,a[u]);
                    if(p == -1)break;
                    v[p]=1;
                    s.z(p);
                    q.push_back(p);
                    c.push_back(p);
                    x=max(x,a[p]);
                }
            }
            
            for(int j:c) o[j]=x;
        }

        return o;
    }
};