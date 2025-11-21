class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size(),res=0;

        for(char ch='a';ch<='z';ch++){
            int l=-1,r=-1;

            for(int i=0;i<n;i++){
                if(s[i]==ch){
                    if(l==-1)l=i;
                    r=i;
                }
            }

            if(l!=-1 && r>l){
                bool seen[26]={0};
                for(int i=l+1;i<r;i++)seen[s[i]-'a']=1;
                for(int i=0;i<26;i++)if(seen[i])res++;
            }
        }

        return res;
    }
};