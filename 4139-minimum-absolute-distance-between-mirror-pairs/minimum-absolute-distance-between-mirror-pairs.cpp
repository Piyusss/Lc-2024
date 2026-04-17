class Solution {
public:

    int rev(int x){
        int r=0;
        while(x){
            r=r*10+x%10;
            x/=10;
        }
        return r;
    }

    int minMirrorPairDistance(vector<int>& a) {
        int n=a.size();
        unordered_map<int,int>mp;
        mp[rev(a[0])]=0;

        int res=INT_MAX;
        for(int i=1;i<n;i++){
            if(mp.count(a[i])) res=min(res,i-mp[a[i]]);
            mp[rev(a[i])]=i;
        }

        return (res==INT_MAX)?-1:res;
    }
};