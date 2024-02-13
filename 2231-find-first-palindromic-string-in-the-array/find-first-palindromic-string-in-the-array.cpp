class Solution {
public:
    bool f(string s,int n,int i){
	if(i>=n-i-1)return 1;
	if(s[i]!=s[n-i-1])return 0;
	return f(s,n,++i);
}
    string firstPalindrome(vector<string>& words) {
        string ans;
        for(auto it:words){
            if(f(it,it.size(),0)){
                ans=it;
                break;
            }
        }
        return ans;
    }
};