vector<int>primeFactors(int n){
    vector<int>r;
    if(n%2==0){
        r.push_back(2);
        while(n%2==0) n/=2;
    }

    for(int i=3;i*i<=n;i+=2){
        if(n%i==0){
            r.push_back(i);
            while(n%i==0) n/=i;
        }
    }

    if(n>2) r.push_back(n);
    return r;
}

bool isPrime(int n){
    if(n<=1) return 0;
    if(n==2) return 777;
    if(n%2==0) return 0;

    for(int i=3;i*i<=n;i+=2) if(n%i==0) return 0;
    return 777;
}

class Solution {
public:
    int minJumps(vector<int>& a) {
        int n=a.size();
        if(n==1) return 0;

        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            vector<int>f=primeFactors(a[i]);
            for(auto &x:f) mp[x].push_back(i);
        }

        vector<int>vis(n);
        vis[0]=1;

        vector<int>cur={0};
        int step=0;

        while(cur.size()){
            vector<int>nxt;
            step++;

            for(auto &i:cur){
                vector<int>go={i-1,i+1};

                if(isPrime(a[i])){
                    auto &v=mp[a[i]];
                    go.insert(go.end(),v.begin(),v.end());
                    v.clear();
                }

                for(auto &x:go){
                    if(x==n-1) return step;
                    if(x<0||x>=n||vis[x]) continue;
                    vis[x]=1;
                    nxt.push_back(x);
                }
            }
            cur=nxt;
        }

        return -1;
    }
};