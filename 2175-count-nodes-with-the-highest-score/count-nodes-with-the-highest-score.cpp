class Solution {
public:

#define ll long long
ll maxi=0;
ll cnt=0;

ll n;

ll dfs(ll node,vector<ll>adjList[]){

    ll l=0;
    ll r=0;

    if(adjList[node].size()==1){
        l=dfs(adjList[node][0],adjList);
    }
    if(adjList[node].size()==2){
        l=dfs(adjList[node][0],adjList);
        r=dfs(adjList[node][1],adjList);
    }

    if(l+r!=n-1){
        if( ((l==0 ? 1 : l) * (r==0 ? 1 : r) * (n-(l+r+1)) ) > maxi){
            maxi=( (l==0 ? 1 : l) * (r==0 ? 1 : r) * (n-(l+r+1)) );
            cnt=1;
        }
        else if( ((l==0 ? 1 : l) * (r==0 ? 1 : r) * (n-(l+r+1)) )== maxi){
            cnt++;
        }
    }
    else if(l+r==n-1){
        if( (l==0 ? 1 : l) * (r==0 ?1 : r) > maxi){
            maxi=(l==0 ? 1 : l) * (r==0 ? 1 : r);
            cnt=1;
        }
        else if( (l==0 ? 1 : l) * (r==0 ? 1 : r) == maxi){
            cnt++;
        }
    }

    return l+r+1;
    
}
    int countHighestScoreNodes(vector<int>& parents) {
        n=parents.size();

        vector<ll>adjList[n+1];
        for(ll i=0;i<n;i++){
            if(parents[i]!=-1) adjList[parents[i]].push_back(i);
        }

        dfs(0,adjList);

        return cnt;
    }
};