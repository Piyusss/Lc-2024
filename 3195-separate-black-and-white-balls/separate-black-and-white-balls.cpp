class Solution {
public:

#define ll long long

    long long minimumSteps(string s) {
        ll n=s.size();

        priority_queue<ll,vector<ll>,greater<ll>>pq;
        ll res=0;

        for(ll i=0;i<n;i++){
            if(s[i]=='1'){
                pq.push(i);
            }
            else{
                if(pq.empty()) continue;

                ll it=pq.top();
                pq.pop();

                swap(s[it],s[i]);
                res+=abs(it-i);
                pq.push(i);
            }
        }

        cout<<s;
        return res;

    }
};