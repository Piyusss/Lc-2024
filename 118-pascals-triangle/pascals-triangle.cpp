class Solution {
public:
// unsigned long long fact(int n){
//     if(n==0 || n==1)return 1;
//     return n*fact(n-1);
// }
unsigned long long f(int n,int r){
    int res=1;
    for(int i=0;i<r;i++){
        res*=(n-i);
        res/=(i+1);
    }
    return res;
}
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=0;i<numRows;i++){
            vector<int>temp;
            for(int j=0;j<i+1;j++){
                temp.push_back(f(i,j));
            }
            ans.push_back(temp);
        }
        return ans;
    }
};