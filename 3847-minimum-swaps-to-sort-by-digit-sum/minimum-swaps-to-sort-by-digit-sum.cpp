class Solution {
public:

    int f(int n){
        int s=0;
        while(n){
            s+=n%10;
            n/=10;
        }
        return s;
    }

    int minSwaps(vector<int>& a) {
        int n=a.size();

        unordered_map<int,int>m;
        vector<pair<int,int>>v;

        for(int i=0;i<n;i++){
            v.push_back({f(a[i]),a[i]});
            m[a[i]]=i;
        }

        sort(v.begin(),v.end());
        int ans=0;

        for(int i=0;i<n;i++){
            if(a[i]==v[i].second) continue;

            int p=m[v[i].second];
            m[a[i]]=p;

            swap(a[p],a[i]);
            ans++;
        }

        return ans;
    }
};