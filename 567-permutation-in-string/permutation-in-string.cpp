class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();

        if(n2<n1)return 0;

        sort(s1.begin(),s1.end());
        
        for(int i=0;i<=n2-n1;i++){
            string st=s2.substr(i,n1);
            sort(st.begin(),st.end());
            if(st==s1)return 1;
        }

        return 0;
    }
};