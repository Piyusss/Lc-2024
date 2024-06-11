class Solution {
public:
#define ll long long
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        ll one=arr1.size();
        ll two=arr2.size();
        
        unordered_map<ll,ll>mp1,mp2;

        for(auto it:arr1)mp1[it]++;
        for(auto it:arr2)mp2[it]++;

        vector<int>ans;

        for(auto it:arr2){
            int cnt=mp1[it];
            for(ll i=1;i<=cnt;i++)ans.push_back(it);
        }

        vector<int>sep;
        for(auto it:arr1){
            if(!mp2[it]){
                sep.push_back(it);
            }
        }
        sort(sep.begin(),sep.end());
        for(auto it:sep)ans.push_back(it);
        return ans;
    }
};