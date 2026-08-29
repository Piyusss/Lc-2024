class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& a,int d) {
        int n=a.size();

        vector<pair<int,int>>v(n);
        for(int i=0;i<n;i++) v[i]={a[i],i};

        sort(v.begin(),v.end());
        vector<int>p;
        
        for(int l=0;l<n;){
            int r=l+1;
            while(r<n&&v[r].first-v[r-1].first<=d) r++;

            p.clear();
            for(int i=l;i<r;i++) p.push_back(v[i].second);

            sort(p.begin(),p.end());
            for(int i=0;i<p.size();i++) a[p[i]]=v[l+i].first;

            l=r;
        }

        return a;
    }
};