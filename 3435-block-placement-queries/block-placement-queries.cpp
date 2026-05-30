class Solution {
public:
    vector<int>seg;
    int MX=50000;

    void update(int node,int l,int r,int idx,int val){
        if(l==r){
            seg[node]=val;
            return;
        }

        int m=(l+r)>>1;

        if(idx<=m) update(node<<1,l,m,idx,val);
        else update(node<<1|1,m+1,r,idx,val);

        seg[node]=max(seg[node<<1],seg[node<<1|1]);
    }

    int query(int node,int l,int r,int ql,int qr){
        if(qr<l||r<ql) return 0;

        if(ql<=l&&r<=qr) return seg[node];

        int m=(l+r)>>1;

        return max(
            query(node<<1,l,m,ql,qr),
            query(node<<1|1,m+1,r,ql,qr)
        );
    }

    vector<bool> getResults(vector<vector<int>>& q) {
        seg.assign(4*(MX+1),0);

        set<int>b;
        b.insert(0);

        for(auto &x:q) if(x[0]==1) b.insert(x[1]);

        vector<int>p(b.begin(),b.end());
        for(int i=1;i<p.size();i++) update(1,0,MX,p[i],p[i]-p[i-1]);

        vector<bool>ans;
        for(int i=q.size()-1;i>=0;i--){
            if(q[i][0]==2){
                int x=q[i][1];
                int sz=q[i][2];

                auto it=prev(b.upper_bound(x));
                int pre=*it;

                int best=query(1,0,MX,0,pre);
                best=max(best,x-pre);

                ans.push_back(best>=sz);
            }
            else{
                int x=q[i][1];

                auto it=b.find(x);
                int l=*prev(it);

                update(1,0,MX,x,0);

                auto rt=next(it);
                if(rt!=b.end()){
                    int r=*rt;
                    update(1,0,MX,r,r-l);
                }

                b.erase(it);
            }
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};