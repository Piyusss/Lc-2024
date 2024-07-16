class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long>degree(n);

        for(auto &it:roads){
            long long u=it[0];
            long long v=it[1];

            degree[u]++;
            degree[v]++;
        }

        // for(auto it:degree)cout<<it<<" ";

        long long ans=0;
        sort(degree.begin(),degree.end());
        long long start=n;

        for(long long i=degree.size()-1;i>=0;i--){
            ans+= (start*degree[i]);
            start--;
        }

        return ans;

        // return (long long)0;
    }
};

// 4*5 + 3*4