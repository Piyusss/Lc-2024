class Solution {
public:
  static bool comp(vector<int> &val1, vector<int> &val2){
      return (val1[1]/val1[0])>(val2[1]/val2[0]);
  }
  
    int maximumUnits(vector<vector<int>>& arr, int w){
        int n=arr.size();

        for(auto &it:arr){
            it[1]=it[1]*it[0];
        }
        sort(arr.begin(),arr.end(),comp);
        
        int ans=0;
        for(int i=0;i<n;i++){
            int pro=arr[i][1];
            int wei=arr[i][0];
            int unit=pro/wei;
            
            if(wei<=w){
                ans+=pro;
                w-=wei;
            }
            else{
                ans+=w*(unit);
                break;
            }
        }        
        
        return ans;
    }
};