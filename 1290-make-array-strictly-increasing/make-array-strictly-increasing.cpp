class Solution {
public:

map<pair<int,int>,int>mp;

int f(vector<int>& arr1,vector<int>& arr2,int idx,int prev){
    if(idx==arr1.size())return 0;

    if(mp[{idx,prev}])return mp[{idx,prev}];

    int res1=1e9;
    if(arr1[idx]>prev){
        res1=0+f(arr1,arr2,idx+1,arr1[idx]);
    }

    int res2=1e9;
    auto it=upper_bound(arr2.begin(),arr2.end(),prev);
    if(it!=arr2.end()){
        int idx_j=it-arr2.begin();
        res2=1+f(arr1,arr2,idx+1,arr2[idx_j]);
    }

    return mp[{idx,prev}]= min(res1,res2);
}
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2){
        sort(arr2.begin(),arr2.end());
        int ans=f(arr1,arr2,0,INT_MIN);

        if(ans==1e9)return -1;
        return ans;
    }
};