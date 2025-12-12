class Solution{

    void g(vector<string>&e,vector<int>&a,vector<int>&b){
        int t=stoi(e[1]);
        vector<string>v;

        stringstream ss(e[2]);
        string x;

        while(ss>>x) v.push_back(x);

        for(auto &s:v){
            if(s=="ALL") for(int i=0;i<a.size();i++)a[i]++;
            else if(s=="HERE"){
                for(int i=0;i<a.size();i++) if(b[i]==0 || b[i]+60<=t) a[i]++;
            }
            else a[stoi(s.substr(2))]++;
        }
    }

public:
    vector<int> countMentions(int n,vector<vector<string>>& e){
        vector<int>a(n),b(n);

        sort(e.begin(),e.end(),[](vector<string>&p,vector<string>&q){
            int t1=stoi(p[1]),t2=stoi(q[1]);
            if(t1==t2) return p[0][1]>q[0][1];
            return t1<t2;
        });

        for(auto &u:e){
            if(u[0]=="MESSAGE") g(u,a,b);
            else{
                int t=stoi(u[1]),id=stoi(u[2]);
                b[id]=t;
            }
        }

        return a;
    }
};