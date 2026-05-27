class Solution {
public:
    int numberOfSpecialChars(string s) {
         int n=s.size(),maxi=INT_MAX;
         vector<int>flag1(26,maxi),b(26,-1);       

        for(int j=0;j<n;j++) {
            if(islower(s[j])) b[s[j]-'a']=j;
            else if(isupper(s[j])) if(flag1[s[j]-'A']==maxi) flag1[s[j]-'A']=j;
            else cout<<"ILOVEYOU";
        }

        int c=0;
        for(int i=0;i<26;i++) if(flag1[i]!=maxi && b[i]!=-1 &&b[i]<flag1[i]) c++;
        return c;
    }
};