class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n=arr.size();

        vector<vector<int>>res;
        sort(arr.begin(),arr.end());

        int mini=INT_MAX;
        
        for(int i=0;i<n-1;i++){
            if(abs(arr[i]-arr[i+1])<mini){
                res.clear();
                mini=abs(arr[i]-arr[i+1]);
                res.push_back({arr[i],arr[i+1]});
            }
            else if(abs(arr[i]-arr[i+1])==mini){
                res.push_back({arr[i],arr[i+1]});
            }
            else continue;
        }

        return res;
    }
};