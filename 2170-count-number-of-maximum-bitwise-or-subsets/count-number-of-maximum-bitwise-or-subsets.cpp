class Solution {
public:

int t,n,cnt=0;
vector<int>res;

bool check(vector<int>& res){
    int start=res[0];
    for(int i=1;i<res.size();i++) start = start | res[i];
    return start == t;
}

void f(vector<int>&nums,int idx){
    if(idx==n){
        if(res.size()!=0 && check(res)) cnt++;
        return;
    }

    res.push_back(nums[idx]);
    f(nums,idx+1);
    res.pop_back();

    f(nums,idx+1);
}

    int countMaxOrSubsets(vector<int>& nums) {
        n=nums.size();

        int start=nums[0];
        for(int i=1;i<n;i++) start = start | nums[i];

        t=start;

        cout<<t;

        f(nums,0);

        return cnt;
        
    }
};