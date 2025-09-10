class Solution{
public:
    static int minimumTeachings(int n, vector<vector<int>>&l, vector<vector<int>>&f2) {
        int m=l.size();

        vector<bitset<501>>k(m);
        for(int i=0;i<m;i++) for(int &l:l[i]) k[i][l]=1;
        bitset<501>need=0;

        for(auto &f:f2){
            int a=f[0]-1,b=f[1]-1;
            if((k[a] & k[b]).any()) continue;
            need[a]=need[b]=1;
        }

        if(!need.any()) return 0;
        int ans=INT_MAX;

        for(int lang=1;lang<=n;lang++){
            int cnt=0;
            for(int i=0;i<m;i++) if(need[i] && !k[i][lang]) cnt++;
            ans=min(ans,cnt);
        }

        return ans;
    }
};