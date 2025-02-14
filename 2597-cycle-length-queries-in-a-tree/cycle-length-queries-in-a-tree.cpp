class Solution {
public:

    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int>res;

        for(auto &it:queries){
            int u=it[0];
            int v=it[1];

            int dist=0;
            while(u != v){
                if(u < v) v >>= 1;
                else u >>= 1;
                dist += 1;
            }

            res.push_back(dist + 1);
        }

        return res;
    }
};