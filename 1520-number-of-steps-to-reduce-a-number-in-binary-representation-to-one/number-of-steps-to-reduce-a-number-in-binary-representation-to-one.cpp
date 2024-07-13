class Solution {
public:
    int numSteps(string s) {
        int n=s.length();
        int ans=0,c=0;

        for(int i=n-1;i>=1;i--){
            if((s[i]-'0'+c)%2==1){
                ans+=2;
                c=1;
            }
            else ans++;
        }
        return ans+c;
    }
};