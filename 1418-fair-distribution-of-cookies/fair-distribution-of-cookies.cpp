class Solution {
public:
int n;
int res=INT_MAX;
void f(int idx,vector<int>&cookies,vector<int>&child,int k){
    if(idx>=n){
        res=min(res,*max_element(child.begin(),child.end()));
        return;
    }
    int cookie=cookies[idx];
    for(int i=0;i<k;i++){
        child[i]+=cookie;
        f(idx+1,cookies,child,k);
        child[i]-=cookie;
    }
}
    int distributeCookies(vector<int>& cookies, int k) {
        n=cookies.size();
        vector<int>child(k,0);
        f(0,cookies,child,k);
        return res;
    }
};