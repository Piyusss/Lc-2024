class Solution {
public:

long long M=1E9+7;
int dp[101][101];

long long f(int n,int goal,int k,long long songs_listened,long long unique_songs_listened){
    if(songs_listened==goal){
        if(unique_songs_listened==n)return 1;
        return 0;
    }

    if(dp[songs_listened][unique_songs_listened]!=-1)return dp[songs_listened][unique_songs_listened];

    long long res=0;

    if(n>unique_songs_listened) res+= ((n-unique_songs_listened)%M * f(n,goal,k,songs_listened+1,unique_songs_listened+1)%M)%M;
    if(unique_songs_listened>k) res+= ((unique_songs_listened-k)%M * f(n,goal,k,songs_listened+1,unique_songs_listened)%M)%M;

    return dp[songs_listened][unique_songs_listened]=res%M;
}
    int numMusicPlaylists(int n, int goal, int k){
        memset(dp,-1,sizeof(dp));
        return f(n,goal,k,(long long)0,(long long)0)%M;
    }
};