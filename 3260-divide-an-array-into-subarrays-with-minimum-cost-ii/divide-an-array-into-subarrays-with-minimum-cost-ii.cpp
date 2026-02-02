class Solution {
public:

    long long minimumCost(vector<int>&a,int k,int d) {
        multiset<int>s,r;
        long long cur=0,best=LLONG_MAX;

        for(int l=1,i=1;i<a.size();i++){
            s.insert(a[i]);
            cur+=a[i];

            if(s.size()>=k){
                auto it=prev(s.end());
                cur-=*it;
                r.insert(*it);
                s.erase(it);
            }

            if(l+d==i){
                best=min(best,cur);
                auto it=s.find(a[l]);

                if(it!=s.end()){
                    cur-=*it;
                    s.erase(it);
                    
                    if(!r.empty()){
                        auto x=*r.begin();
                        r.erase(r.begin());
                        s.insert(x);
                        cur+=x;
                    }
                }

                else{
                    it=r.find(a[l]);
                    if(it!=r.end())r.erase(it);
                }

                l++;
            }
        }

        return a[0]+best;
    }
};