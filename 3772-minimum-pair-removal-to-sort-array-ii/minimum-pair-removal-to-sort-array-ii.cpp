class Solution {
public:
    int minimumPairRemoval(vector<int>&a) {
        int n=a.size();
        vector<long long>v(n);
        for(int i=0;i<n;i++)v[i]=a[i];

        vector<int> l(n),r(n);
        for(int i=0;i<n;i++){
            l[i]=i-1;
            r[i]=i+1;
        }

        set<pair<long long,int>>s;
        int bad=0;
        for(int i=0;i+1<n;i++){
            if(v[i]>v[i+1])bad++;
            s.insert({v[i]+v[i+1],i});
        }

        int ops=0;
        while(bad){
            auto it=*s.begin();
            s.erase(s.begin());

            int i=it.second;
            int j=r[i];
            int li=l[i], rj=r[j];

            if(v[i]>v[j])bad--;

            long long sum=it.first;

            if(li>=0){
                if(v[li]<=v[i]){
                    if(v[li]>sum)bad++;
                }
                else{
                    if(v[li]<=sum)bad--;
                }
                s.erase({v[li]+v[i],li});
                s.insert({v[li]+sum,li});
            }

            if(rj<n){
                if(v[j]<=v[rj]){
                    if(sum>v[rj])bad++;
                }
                else{
                    if(sum<=v[rj])bad--;
                }
                s.erase({v[j]+v[rj],j});
                s.insert({sum+v[rj],i});
                l[rj]=i;
            }

            r[i]=rj;
            v[i]=sum;
            ops++;
        }

        return ops;
    }
};