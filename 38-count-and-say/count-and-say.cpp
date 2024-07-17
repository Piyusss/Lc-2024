class Solution {
public:

string f(int n){
    if(n==1)return "1";

    string st=f(n-1);

    //Processing of st
    string ans="";
    for(int i=0;i<st.size();i++){
        int cnt=1;
        char ch=st[i];
        while(i<st.size()-1 && st[i]==st[i+1]){
            cnt++;
            i++;
        }
        ans+=to_string(cnt)+string(1,ch);
    }

    return ans;

}
    string countAndSay(int n) {
        return f(n);
    }
};