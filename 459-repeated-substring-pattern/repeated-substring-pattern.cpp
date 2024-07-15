class Solution {
public:
    void computeLps(string& s,vector<int>& lps){
        int n=s.size();
        int len=0;  
        int i=1;
        while(i<n){
            if(s[i]==s[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len!=0)len=lps[len-1];
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
    }
    bool repeatedSubstringPattern(string s){
        int n=s.size();
        vector<int>lps(n);

        computeLps(s,lps);

        int maxi=lps[n-1];

        if(maxi>0 && n%(n-maxi)==0)return 1;
        return 0;
    }
};