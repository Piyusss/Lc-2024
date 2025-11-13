class Solution {
public:
    int maxOperations(string s) {
        int c=0,ans=0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='1')c++;
            else if(i&&s[i-1]=='1')ans+=c;
        }
        
        return ans;
    }
};