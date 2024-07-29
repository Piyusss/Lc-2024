class Solution {
public:

int dp[1000+1][1000+1][5];

int f(vector<int>& rating,int idx,int cnt,int prev){
    if(cnt==3)return 1;
    if(idx==rating.size())return 0;

    if(prev!=-1 &&  dp[idx][prev][cnt]!=-1)return dp[idx][prev][cnt];

    int pick=0;
    int not_pick=0;

    if(prev==-1 || rating[idx]>rating[prev]) pick+=f(rating,idx+1,cnt+1,idx);
    not_pick+=f(rating,idx+1,cnt,prev);

    if(prev==-1)prev=0;
    return dp[idx][prev][cnt]= pick+not_pick;
}
    int numTeams(vector<int>& rating) {
        int cnt=0;
        
        memset(dp,-1,sizeof(dp));
        cnt+=f(rating,0,0,-1);
        reverse(rating.begin(),rating.end());
        memset(dp,-1,sizeof(dp));
        cnt+=f(rating,0,0,-1);

        return cnt;
    }
};