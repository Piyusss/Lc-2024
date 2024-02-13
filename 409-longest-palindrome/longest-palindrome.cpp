class Solution {
public:
    int longestPalindrome(string s) {
         int n=s.size();
         map<char,int>mp;
         for(auto it:s)mp[it]++;
         int cnt=0;int flag=0;
         //now
         if(n%2==0){
             for(auto it:mp){
                 if(it.second%2==0){
                     cnt+=it.second;
                 }
             }
             for(auto it:mp){
                 if(it.second%2!=0){
                     cnt+=((it.second)/2)*(2);
                     flag=1;
                 }
             }
             for(auto it:mp){
                 if(it.second==1 || flag){
                     cnt++;
                     break;
                 }
             }
        }
        //now
        else{
            for(auto it:mp){
                 if(it.second%2==0){
                     cnt+=it.second;
                 }
             }
             for(auto it:mp){
                 if(it.second%2!=0){
                     cnt+=((it.second)/2)*(2);
                     flag=1;
                 }
             }
             for(auto it:mp){
                 if(it.second==1 || flag){
                     cnt++;
                     break;
                 }
             }
        }
        return cnt;
    }
};