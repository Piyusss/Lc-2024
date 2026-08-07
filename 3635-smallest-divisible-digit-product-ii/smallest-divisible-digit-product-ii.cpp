using ll=long long;

class Solution {
public:

    ll gcd(ll a,ll b){
        if(!a) return b;
        return gcd(b%a,a);
    }

    bool f(const string&a,const string&b){
        if(a.size()!=b.size()) return a.size()>b.size();
        return a>b;
    }

    string smallestNumber(string s,long t){
        int n=s.size();

        vector<ll>r(n+1);
        r[0]=t;

        int e=n;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                e=i+1;
                break;
            }
            r[i+1]=r[i]/gcd(r[i],s[i]-'0');
        }

        if(e==n && r[n]==1) return s;
        for(int i=e-1;i>=0;i--){
            while(s[i]<'9'){
                ll x=r[i];
                s[i]++;
                x/=gcd(x,s[i]-'0');

                for(int j=n-1;j>i;j--){
                    for(int k=9;k>0;k--){
                        if(x%k==0){
                            x/=k;
                            s[j]='0'+k;
                            break;
                        }
                    }
                }
                if(x==1) return s;
            }
        }

        string ans;
        for(int i=9;t>1&&i>1;i--){
            while(t%i==0){
                ans+=to_string(i);
                t/=i;
            }
        }

        if(t!=1) return "-1";
        reverse(ans.begin(),ans.end());

        if(f(ans,s)) return ans;
        if(ans.size()==s.size()) return "1"+ans;

        int d=s.size()-ans.size();
        string cur=string(d,'1')+ans;

        if(f(cur,s)) return cur;
        return string(d+1,'1')+ans;
    }
};