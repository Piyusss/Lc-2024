class Solution {
public:
vector<vector<string>>ans;
vector<string>temp;
int n;

bool isPal(string s,int start,int end){
    while(start<=end){
        if(s[start++]!=s[end--])return 0;
    }
    return 1;
}
void f(int ind,string s){
    if(ind==n){
        ans.push_back(temp);
        return;
    }

    for(int i=ind;i<n;i++){
        if(isPal(s,ind,i)){
            temp.push_back(s.substr(ind,i-ind+1));
            f(i+1,s);
            temp.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        n=s.size();

        f(0,s);

        return ans;
    }
};