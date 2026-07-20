class Solution {
public:

    bool f(int mid,vector<int>&nums,int t,int n){
        int totDays=0;
        int temp=0;

        for(int i=0;i<n;i++){
            temp+=nums[i];

            if(temp==mid){
                totDays++;
                temp=0;
            }
            else if(temp<mid){
                continue;
            }
            else{
                totDays++;
                temp=0;
                i--;
            }
        }

        if(temp) totDays++;
        return totDays<=t;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();

        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        int mid=-1;

        while(low<high){
            mid=low+(high-low)/2;

            if(f(mid,weights,days,n)) high=mid;
            else low=mid+1;
        }

        return high;
    }
};