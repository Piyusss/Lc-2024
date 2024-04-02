class Solution {
public:
int m;
set<vector<int>>ans;
    void f(vector<int>&nums,int idx,vector<int>&temp,int k){
        if(idx>=m){
            if(temp.size()==k){
                bool flag=1;
                for(int i=0;i<temp.size()-1;i++){
                    if(temp[i+1]<temp[i]){
                        flag=0;break;
                    }
                }
                if(flag==1)ans.insert(temp);
            }
            return;
        }

        temp.push_back(nums[idx]);
        f(nums,idx+1,temp,k);
        temp.pop_back();
        f(nums,idx+1,temp,k);
    }
    vector<vector<int>> combine(int n, int k) {
        //now
        m=n;
        vector<int>nums;
        for(int i=1;i<=n;i++)nums.push_back(i);
        vector<int>temp;
        f(nums,0,temp,k);
        vector<vector<int>>final;
        for(auto &it:ans){
            final.push_back(it);
        }
        return final;
    }
};