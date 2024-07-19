class Solution {
public:

vector<int> adjList[11];
int M=1e9+7;
int dp[5000+1][10];

    int knightDialer(int n){
        int ans=0;
        memset(dp,0,sizeof(dp));

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
        
        for(int i=0;i<=9;i++)dp[0][i]=1;

        for(int step=1;step<=n-1;step++){
            for(int num=0;num<=9;num++){
                int res=0;
                for(auto& it:adjList[num]){
                    res=(res+dp[step-1][it])%M;
                }
                dp[step][num]= res%M;
            }
        }
        
        for(int i=0;i<=9;i++)ans=(ans+dp[n-1][i])%M;
        return ans%M;
    }
};