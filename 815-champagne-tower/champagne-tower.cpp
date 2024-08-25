class Solution {
public:

double dp[105][105];

double f(int poured,int i,int j){
    if(i<0 || j<0 || i<j)return 0.0;
    if(i==0 && j==0)return poured;

    if(dp[i][j]!=-1.0)return dp[i][j];

    double up_left=(f(poured,i-1,j-1)-1)/2.0;
    double up_right=(f(poured,i-1,j)-1)/2.0;

    return dp[i][j]=(up_left<0 ? 0.0 : up_left) + (up_right<0 ? 0.0 : up_right);
}
    double champagneTower(int poured, int i, int j){
        for(int i=0;i<101;i++){
            for(int j=0;j<101;j++){
                dp[i][j]=-1.0;
            }
        }

        return min(1.0,f(poured,i,j));
    }
};