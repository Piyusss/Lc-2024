class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>res;

        if(n&1){
            res.push_back(0);
            for(int i=1;i<=(n-1)/2;i++){
                res.push_back(i);
                res.push_back(-i);
            }
        }
        else{
            for(int i=1;i<=n/2;i++){
                res.push_back(i);
                res.push_back(-i);
            } 
        }
        

        return res;
    }
};