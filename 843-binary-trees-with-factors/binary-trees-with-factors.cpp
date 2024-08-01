class Solution {
public:

int MOD=1e9+7;

    int numFactoredBinaryTrees(vector<int>& arr){
        int n=arr.size();
        sort(arr.begin(),arr.end());
        
        unordered_map<int,long long>mp;
        mp[arr[0]]=1;

        for(int i=0;i<n;i++){
            int root=arr[i];
            mp[root]=1;
            for(int j=0;j<i;j++){
                int left_child=arr[j];
                int right_child=root/left_child;

                if(root%left_child==0 && mp.find(right_child)!=mp.end()){
                    mp[root]+= mp[left_child]*mp[right_child];
                }
            } 
        }

        long long res=0;
        for(auto &it:mp){
            res=(res+it.second)%MOD;
        }
        return (int)res;
    }
};