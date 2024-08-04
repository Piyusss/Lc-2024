class Solution {
public:

int M=1E9+7;

    int rangeSum(vector<int>& nums, int n, int left, int right) {

        vector<int>v;
        
        for(int i=0;i<n;i++){
            int sum=nums[i];
            for(int j=i+1;j<n;j++){
                v.push_back(sum);
                sum+=nums[j];
            }
            v.push_back(sum);
        }

    sort(v.begin(),v.end());

    left--;
    right--;

    int ans=0;
    for(int i=left;i<=right;i++){
        ans=(ans+v[i])%M;
    }
    return ans%M;

    }
};