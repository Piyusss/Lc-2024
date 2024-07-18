class Solution {
public:

bool canWork(int mid,vector<int>& nums,int k,int m){
    int n=nums.size();
    int cnt=0;
    int flag=0;

    for(int i=0;i<n;i++){
        if(nums[i]<=mid){
            cnt++;
            if(cnt==k){
                flag++;
                cnt=0;
            }
        }
        else cnt=0;
    }

    if(flag>=m)return 1;
    return 0;

}
    int minDays(vector<int>& nums, int m, int k) {
        int n=nums.size();

        int l=1;
        int r=*max_element(nums.begin(),nums.end());
        int ans=-1;

        while(l<=r){
            int mid=l+(r-l)/2;

            if(canWork(mid,nums,k,m)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }

        return ans;
    }
};