class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int n=nums.size();
        vector<int>odd;vector<int>even;
        for(int i=0;i<n;i++){
            if(i&1)odd.push_back(nums[i]);
            else even.push_back(nums[i]);
        }
        //now
        sort(odd.begin(),odd.end(),greater<int>());
        sort(even.begin(),even.end());
        //now
        vector<int>ans;int s=min(odd.size(),even.size());
        for(int i=0;i<s;i++){
            ans.push_back(even[i]);
            ans.push_back(odd[i]);
        }
        if(even.size()>odd.size()){
            for(int i=s;i<even.size();i++)ans.push_back(even[i]);
        }
        if(even.size()<odd.size()){
            for(int i=s;i<odd.size();i++)ans.push_back(odd[i]);
        }
        return ans;
    }
};