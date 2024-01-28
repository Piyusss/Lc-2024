class Solution {
public:
int subarraySum(vector<int>& v, int k) {
        map<int,int>mp;mp[0]=1;
        int prefixSum=0,cnt=0;
        for(int i=0;i<v.size();i++){
            prefixSum+=v[i];
            cnt+=mp[prefixSum-k];
            mp[prefixSum]++;
        }
        return cnt;
    }
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
         int cnt=0;
        for(int i=0;i<matrix.size();i++){
            vector<int>sum(matrix[0].size(),0);
            for(int j=i;j<matrix.size();j++){
                for(int k=0;k<matrix[0].size();k++){
                    sum[k]+=matrix[j][k];
                }
                cnt+=subarraySum(sum,target);
            }
        }
        return cnt;
    }
};