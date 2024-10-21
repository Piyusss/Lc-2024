class Solution {
public:

int maxi=0,n;
unordered_set<string>st;

void f(int idx,int cnt,string &s){
    if(idx==n){
        maxi=max(maxi,cnt);
        return;
    }

    string flag="";
    for(int i=idx;i<n;i++){
        flag += s[i];
        if(st.find(flag)==st.end()){
            st.insert(flag);
            f(i+1,cnt+1,s);
            st.erase(flag);
        }
    }
}
    int maxUniqueSplit(string s){
        n=s.size();

        f(0,0,s);

        return maxi;
    }
};