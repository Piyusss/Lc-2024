class Solution {
public:
    bool isBalanced(string s){
        int n=s.size();

        int even=0,odd=0;
        for(int i=1;i<=n;i++){
            if(i&1){
                odd+=(s[i-1]-'0');
            }
            else{
                even+=(s[i-1]-'0');
            }
        }

        return even==odd;
    }
};