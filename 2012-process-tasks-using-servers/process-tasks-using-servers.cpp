using ll=long long;

class Solution {
public:
    vector<int> assignTasks(vector<int>& s, vector<int>& t) {
        int n=s.size(),m=t.size();

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>f;
        priority_queue<pair<ll,pair<int,int>>,vector<pair<ll,pair<int,int>>>,greater<pair<ll,pair<int,int>>>>b;

        for(int i=0;i<n;i++) f.push({s[i],i});
        vector<int>ans(m);

        for(int i=0;i<m;i++){
            while(!b.empty() && b.top().first<=i){
                f.push(b.top().second);
                b.pop();
            }

            if(!f.empty()){
                auto [x,y]=f.top();
                f.pop();

                ans[i]=y;
                b.push({i+t[i],{x,y}});
            }
            else{
                auto [x,y]=b.top();
                b.pop();

                ans[i]=y.second;
                b.push({x+t[i],y});
            }
        }

        return ans;
    }
};