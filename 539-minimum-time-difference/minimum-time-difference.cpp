class Solution {
public:

int mini=INT_MAX;

void f(int n,vector<string>&nums,int i,int j){
    if(j==-1)j=0;
    int h1=stoi(nums[i].substr(0,2));
    int m1=stoi(nums[i].substr(3,2));
    int h2=stoi(nums[j].substr(0,2));
    int m2=stoi(nums[j].substr(3,2));

    int dif=abs((h1*60+m1)-(h2*60+m2));
    mini=min(mini,min(dif,1440-(dif)));
}
    int findMinDifference(vector<string>& nums){
        int n=nums.size();

        sort(nums.begin(),nums.end());
        for(auto it:nums)cout<<it<<" ";

        for(int i=1;i<n;i++) f(n,nums,i,i-1);
        f(n,nums,n-1,-1);

        return mini;
    }
};