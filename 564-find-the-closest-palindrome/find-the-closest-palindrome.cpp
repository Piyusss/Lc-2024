class Solution {
public:
#define pb push_back
long f(long n,long orSize){
    string s=to_string(n);
    string ans=s;

    long end=s.size()-1;
    if(orSize&1)end--;

    for(long i=end;i>=0;i--)ans+=s[i];

    return stol(ans);
}
    string nearestPalindromic(string s){
        long n=s.size();

        long mid=n/2;

        if(n&1)mid++;

        long firstHalf=stol(s.substr(0,mid));
        cout<<firstHalf<<endl;
        vector<long>possibilities;

        possibilities.pb(f(firstHalf,n));
        possibilities.pb(f(firstHalf+1,n));
        possibilities.pb(f(firstHalf-1,n));
        possibilities.pb((pow(10,n)+1));
        possibilities.pb((pow(10,n-1)-1));

        for(long it:possibilities)cout<<it<<endl;

        sort(possibilities.begin(),possibilities.end());

        long res=-1;
        long absDif=INT_MAX;

        for(auto &it:possibilities){
            if(it!=stol(s)){
                if(abs(it-stol(s))<absDif){
                    res=it;
                    absDif=abs(it-stol(s));
                }
            }
        }

        return to_string(res);
    }
};