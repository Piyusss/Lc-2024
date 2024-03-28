class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        vector<string>ans;
        //now
        string temp="";
        for(int i=0;i<n;i++){
            if(s[i]!=' '){
                temp+=s[i];
                if(i==n-1)ans.push_back(temp);
            }
            else {
                if(temp.size()>=1)ans.push_back(temp);
                temp="";
            }
        }
        reverse(ans.begin(),ans.end());
        //now
        string res="";
        for(int i=0;i<=ans.size()-1;i++){
            if(i<ans.size()-1){
                res+=ans[i];
                res+=" ";
            }
            else res+=ans[i];
        }
        return res;
    }
};