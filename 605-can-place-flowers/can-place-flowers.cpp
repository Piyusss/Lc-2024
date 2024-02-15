class Solution {
public:
    bool canPlaceFlowers(vector<int>& v, int n) {
        int s=v.size();
        int cnt=0;
        if(s==1 && v[0]==0)return 1;
        if(s==1 && v[0]==1){
            if(n==0)return 1;
            return 0;
        }
        if(v[0]==0){
            if(v[1]==0){
                cnt++;v[0]=1;
            }
        }
        for(int i=1;i<s;i++){
                if(i==s-1){
                    if(v[i]==0 && v[i-1]==0)cnt++;
                    continue;
                }
            if(v[i]==0){
                if(v[i-1]==0 && v[i+1]==0){
                    v[i]=1;
                    cnt++;
                }
            }
        }
        if(n<=cnt)return 1;
        return 0;
    }
};
//0 1 0