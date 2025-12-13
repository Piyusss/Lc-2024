class Solution{
public:
    vector<string> validateCoupons(vector<string>& c,vector<string>& l,vector<bool>& a) {
        unordered_map<string,int>m;
        m["electronics"]=1;
        m["grocery"]=2;
        m["pharmacy"]=3;
        m["restaurant"]=4;

        auto ok=[&](char x){
            return (x>='a'&&x<='z')||(x>='A'&&x<='Z')||(x>='0'&&x<='9')||x=='_';
        };

        vector<int>v;
        int n=c.size();
        
        for(int i=0;i<n;i++){
            if(!m[l[i]] || c[i].empty())a[i]=0;
            if(a[i]){
                for(char x:c[i]){
                    if(!ok(x)){
                        a[i]=0;
                        break;
                    }
                }
            }
            if(a[i])v.push_back(i);
        }

        sort(v.begin(),v.end(),[&](int i,int j){
            if(m[l[i]]!=m[l[j]])return m[l[i]]<m[l[j]];
            return c[i]<c[j];
        });

        vector<string>r;
        for(int &i:v)r.push_back(c[i]);
        return r;
    }
};