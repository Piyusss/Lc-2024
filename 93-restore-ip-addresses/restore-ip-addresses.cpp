class Solution {
public:

int n;
string s;
vector<string>res;

bool check(string st){
    if(st[0]=='0' || stoi(st)>255)return 0;
    return 1;
}

void f(int idx,int part,string cur){
    if(idx==n && cur.size()==n+4 && part==4){
        cur.pop_back();
        res.push_back(cur);
        return;
    }

    if(idx<=n-1) f( idx+1, part+1 , cur + s.substr(idx,1) + ".");
    if(idx<=n-2 && check(s.substr(idx,2))) f( idx+2, part+1 , cur + s.substr(idx,2) + ".");
    if(idx<=n-3 && check(s.substr(idx,3))) f( idx+3, part+1 , cur + s.substr(idx,3) + ".");

}
    vector<string> restoreIpAddresses(string S){
        n=S.size();
        if(n>12) return res;

        s=S;
        f(0,0,"");

        return res;

    }
};