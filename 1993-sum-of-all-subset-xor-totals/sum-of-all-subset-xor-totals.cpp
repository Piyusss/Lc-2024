class Solution {
public:
#define ll long long
int ans=0;
int n;

void func(int ind,int sum,vector<int>&arr){
  if(ind==n){
    ans+=sum;
    return;
  }
  //pick-up the element
  func(ind+1,sum^arr[ind],arr);

  //not pick-up the element
  func(ind+1,sum,arr);
}
    int subsetXORSum(vector<int>& nums) {
        n=nums.size();
        func(0,0,nums);
        return ans;
    }
};