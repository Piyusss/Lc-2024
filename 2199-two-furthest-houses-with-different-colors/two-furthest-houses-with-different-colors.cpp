class Solution {
public:
    int maxDistance(vector<int>& a) {
        int n=a.size()-1,res=0;
        
        for(int i=0;i<n;i++){
            if(a[i]!=a[n]){
                res=max(res,n-i);
                break;
            }
        }

        for(int i=n;i>=0;i--){
            if(a[i]!=a[0]){
                res=max(res,i);
                break;
            }
        }

        return res;
    }
};