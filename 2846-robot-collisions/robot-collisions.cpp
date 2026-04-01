using ll=long long;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& p,vector<int>& h,string d) {
        int n=p.size();

        vector<tuple<ll,ll,ll>>v;
        stack<tuple<ll,ll,ll>>st;
        unordered_map<ll,ll>mp;

        for(int i=0;i<n;i++) v.push_back({p[i],h[i],d[i]=='R'});
        sort(v.begin(),v.end());

        for(auto &t:v){
            auto [x,y,z]=t;
            if(st.empty()){
                if(!z) mp[x]=y;
                else st.push({x,y,z});
                continue;
            }

            if(z){
                st.push({x,y,z});
                continue;
            }
            if(get<1>(st.top())==y){
                mp[get<0>(st.top())]=0;
                st.pop();
                mp[x]=0;
                continue;
            }

            while(!st.empty() && get<1>(st.top())<y){
                mp[get<0>(st.top())]=0;
                st.pop();
                y--;
            }

            if(!st.empty()&&get<1>(st.top())==y){
                mp[get<0>(st.top())]=0;
                st.pop();
                mp[x]=0;
                continue;
            }

            if(st.empty()) mp[x]=y;
            else{
                mp[x]=0;
                auto [a,b,c]=st.top(); st.pop();
                b--;
                mp[a]=b;
                st.push({a,b,c});
            }
        }

        while(!st.empty()){
            mp[get<0>(st.top())]=get<1>(st.top());
            st.pop();
        }

        vector<int>r;
        for(auto &x:p) if(mp[x]>0) r.push_back(mp[x]);
        return r;
    }
};