class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int>mp(k);
        
        for(auto &it:arr) mp[( it%k + k) % k]++;

        if(mp[0] %2 !=0)return 0;
        for(int i=1;i<=k/2;i++) if(mp[k-i] != mp[i])return 0;

        return 1;
    }
};