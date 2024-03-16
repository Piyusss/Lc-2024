class Solution {
public:
    int findMaxLength(vector<int>& v){
        int k=0;
        for(int i=0;i<v.size();i++)if(v[i]==0)v[i]=-1;
        map<int,int>mp;mp[0]=-1;
        int sum=0,maxi=0;
        for(int i=0;i<v.size();i++){
            sum+=v[i];
            if(mp.find(sum)==mp.end())mp[sum]=i;
            else maxi=max(maxi,i-mp[sum]);
        }
        return maxi;
    }
};