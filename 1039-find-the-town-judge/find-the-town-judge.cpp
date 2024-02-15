class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>v(n+1);
        //now
        for(auto &it:trust){
            v[it[0]]--;
            v[it[1]]++;
        }
        //now
        for(int i=1;i<=n;i++){
            if(v[i]==n-1)return i;
        }
        return -1;
    }
};