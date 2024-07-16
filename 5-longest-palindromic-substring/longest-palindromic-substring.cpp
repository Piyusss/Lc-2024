class Solution {
public:

bool isPal(string &s,int i,int j){
    while(i<=j){
        if(s[i++]!=s[j--])return 0;
    }
            return 1;
}
    string longestPalindrome(string s) {
        int n=s.size();
        
        int max_len=0;
        int sp=0;
         for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPal(s,i,j)){
                    if(max_len<j-i+1){
                        max_len=j-i+1;
                        sp=i;
                    }
                }
            }
         }
         return s.substr(sp,max_len);
    }
};