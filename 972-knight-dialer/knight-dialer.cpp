class Solution {
public:

vector<int> adjList[10];
int M=1e9+7;
int dp[10][5000+1];

int f(int num,int step){
    if(step==0)return 1;

    if(dp[num][step]!=-1)return dp[num][step];

    int res=0;
    for(auto& it:adjList[num]){
        res=(res+f(it,step-1))%M;
    }

    return dp[num][step]= res%M;
}
    int knightDialer(int n){
        int ans=0;
        memset(dp,-1,sizeof(dp));

        adjList[0].push_back(4);adjList[0].push_back(6);//0
        adjList[1].push_back(6);adjList[1].push_back(8);//1
        adjList[2].push_back(7);adjList[2].push_back(9);//2
        adjList[3].push_back(4);adjList[3].push_back(8);//3
        adjList[4].push_back(3);adjList[4].push_back(9);adjList[4].push_back(0);//4
        // adjList[0].push_back(4);adjList[0].push_back(6);//5
        adjList[6].push_back(1);adjList[6].push_back(7);adjList[6].push_back(0);//6
        adjList[7].push_back(2);adjList[7].push_back(6);//7
        adjList[8].push_back(1);adjList[8].push_back(3);//8
        adjList[9].push_back(2);adjList[9].push_back(4);//9

        for(int i=0;i<=9;i++){
            ans=(ans+f(i,n-1))%M;
        }
        
        return ans%M;
    }
};