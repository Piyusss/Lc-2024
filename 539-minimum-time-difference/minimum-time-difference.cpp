class Solution {
public:
    int findMinDifference(vector<string>& nums){
        int n=nums.size();

        sort(nums.begin(),nums.end());
        for(auto it:nums)cout<<it<<" ";

        int mini=INT_MAX;
        for(int i=1;i<n;i++){
            int h1=stoi(nums[i].substr(0,2));
            int m1=stoi(nums[i].substr(3,2));
            int h2=stoi(nums[i-1].substr(0,2));
            int m2=stoi(nums[i-1].substr(3,2));

            int dif=abs((h1*60+m1)-(h2*60+m2));
            mini=min(mini,min(dif,1440-(dif)));
        }

        int h1=stoi(nums[0].substr(0,2));
        int m1=stoi(nums[0].substr(3,2));
        int h2=stoi(nums[n-1].substr(0,2));
        int m2=stoi(nums[n-1].substr(3,2));

        int dif=abs((h1*60+m1)-(h2*60+m2));
        mini=min(mini,min(dif,1440-(dif)));

        return mini;
    }
};