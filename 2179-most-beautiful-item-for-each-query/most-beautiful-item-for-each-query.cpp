class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries){
        int n=items.size(),m=queries.size();
        sort(items.begin(),items.end());

        vector<int>res(m,0),maxBeauty(n);
        maxBeauty[0]=items[0][1];
        for(int i=1;i<n;i++) maxBeauty[i]=max(maxBeauty[i-1],items[i][1]);

        int id=0;
        for(auto &it:queries){
            vector<int>flag={it,INT_MAX};
            auto idx=upper_bound(items.begin(),items.end(),flag);
            int prevIdx=(idx-items.begin())-1;

            if(prevIdx>=0) res[id]=maxBeauty[prevIdx];
            id+=1;
        }

        return res;

    }
};