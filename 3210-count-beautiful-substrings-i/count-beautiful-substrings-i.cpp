class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        int n=s.size();

        int ans=0;
        unordered_set<int>st={'a','e','i','o','u'};
        for(int i=0;i<n;i++){
            int v=0,c=0;
            string temp="";
            for(int j=i;j<n;j++){
                if(st.count(s[j]))v++;
                else c++;

                if(v==c && (v*c)%k==0)ans++;
            }
        }

        return ans;
    }
};