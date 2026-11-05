class Solution {
public:
    bool f(int x,vector<int>&a,int d){
        for(auto &y:a) if(abs(x-y)<=d) return 0;
        return 1;
    }

    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n=arr1.size(),ans=0;
        
        for(auto &x:arr1) if(f(x,arr2,d)) ans+=1;
        return ans;
    }
};