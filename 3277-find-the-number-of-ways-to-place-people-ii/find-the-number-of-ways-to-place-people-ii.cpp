class Solution{
public:

    static bool comp(vector<int>&a,vector<int>&b){
        return (a[0]==b[0]) ? (a[1]>b[1]) : (a[0]<b[0]);
    }

    int numberOfPairs(vector<vector<int>>&p){
        int n=p.size(),r=0,m=INT_MAX;
        sort(p.begin(),p.end(),comp);

        for(int i=0;i<n;i++){
            m=INT_MAX;
            for(int j=i-1;j>=0;j--){
                if(p[j][1]>=p[i][1] && m>p[j][1]){
                    m=p[j][1];
                    r++;
                }
            }
        }

        return r;
    }
};