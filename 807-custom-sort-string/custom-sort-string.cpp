class Solution {
public:
    string customSortString(string order, string s){
        string ans="";
        vector<pair<char,int>>mp;
        for(int i=0;i<order.size();i++){
            int cnt=count(s.begin(),s.end(),order[i]);
            if(cnt!=0)mp.push_back({order[i],cnt});
        }
        //now
        for(auto it:mp){
            char ch=it.first;
            int freq=it.second;
            while(freq--){
                ans+=ch;
            }
        }
        //now
        for(int i=0;i<s.size();i++){
            if(count(order.begin(),order.end(),s[i])==0){
                ans+=s[i];
            }
        }
        return ans;
    }
};