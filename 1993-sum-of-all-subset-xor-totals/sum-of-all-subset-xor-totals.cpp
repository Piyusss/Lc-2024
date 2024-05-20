class Solution {
public:

int ans=0;
int n;

void f(int ind,int sum,vector<int>&arr){
  if(ind==n){
    ans+=sum;
    return;
  }
  //pick-up the element
  f(ind+1,sum^arr[ind],arr);

  //not pick-up the element
  f(ind+1,sum,arr);
}
    int subsetXORSum(vector<int>& nums) {
        n=nums.size();
        f(0,0,nums);
        return ans;
    }
};