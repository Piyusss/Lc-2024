class Solution {
public:

    const int M=1E9+7;

    int maximizeSquareArea(int m, int n, vector<int>& h, vector<int>& v) {
        
        h.push_back(1);h.push_back(m);
        v.push_back(1);v.push_back(n);

        sort(h.begin(),h.end());
        sort(v.begin(),v.end());

        set<int>sh;
        int hs=h.size(),vs=v.size();

        for(int i=0;i<hs;i++){
            for(int j=i+1;j<hs;j++){
                sh.insert(h[j]-h[i]);
            }
        }

        int best=-1;
        for(int i=0;i<vs;i++){
            for(int j=i+1;j<vs;j++){
                int d=v[j]-v[i];
                if(sh.count(d)) best=max(best,d);
            }
        }

        if(best==-1) return -1;
        return (int)((1LL*best*best)%M);
    }
};