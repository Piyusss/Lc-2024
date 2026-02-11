class SegmentTree {
    int n,s;
    vector<int>mn,mx,lz;

    void push(int i,int l,int r){
        if(!lz[i])return;
        mn[i]+=lz[i];
        mx[i]+=lz[i];
        if(l<r){
            lz[i<<1]+=lz[i];
            lz[i<<1|1]+=lz[i];
        }
        lz[i]=0;
    }

    void upd(int L,int R,int v,int i,int l,int r){
        push(i,l,r);
        if(R<l||L>r) return;

        if(L<=l&&r<=R){
            lz[i]+=v;
            push(i,l,r);
            return;
        }

        int m=(l+r)>>1;
        upd(L,R,v,i<<1,l,m);
        upd(L,R,v,i<<1|1,m+1,r);

        mn[i]=min(mn[i<<1],mn[i<<1|1]);
        mx[i]=max(mx[i<<1],mx[i<<1|1]);
    }

    int qry(int L,int R,int i,int l,int r){
        push(i,l,r);
        if(R<l||L>r) return -1;

        if(mn[i]>0||mx[i]<0) return -1;
        if(l==r) return mn[i]==0?l:-1;

        int m=(l+r)>>1;
        int x=qry(L,R,i<<1,l,m);

        if(x!=-1) return x;
        return qry(L,R,i<<1|1,m+1,r);
    }

public:
    SegmentTree(int n):n(n){
        s=1;
        while(s<n)s<<=1;

        mn.assign(s<<1,0);
        mx.assign(s<<1,0);
        lz.assign(s<<1,0);
    }

    void add(int l,int r,int v){upd(l,r,v,1,0,s-1);}
    int get(int l,int r){return qry(l,r,1,0,s-1);}
};

class Solution {
public:

    int longestBalanced(vector<int>&a) {
        int n=a.size(),res=0;
        SegmentTree t(n);

        unordered_map<int,int>mp;

        for(int j=0;j<n;j++){
            int x=a[j];
            int p=mp.count(x)?mp[x]:-1;
            int l=p+1,r=j;

            t.add(l,r,(x&1)?1:-1);
            mp[x]=j;

            int i=t.get(0,j);
            if(i!=-1)res=max(res,j-i+1);
        }

        return res;
    }
};