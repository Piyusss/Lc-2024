class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& a) {
        int n=a.size(),m=a[0].size(),res=0;

        vector<pair<int,int>>d(m);

        for(auto &r:a){
            int s=0,f=0;

            for(int i=0;i<m;i++){
                if(r[i]=='X'){f=1;s++;}
                else if(r[i]=='Y') s--;

                d[i].first|=f;
                d[i].second+=s;

                if(d[i].first && d[i].second==0) res++;
            }
        }
        
        return res;
    }
};