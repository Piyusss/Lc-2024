class MyCalendarThree {
public:

    multiset<pair<int,int>>lines;
    int book(int start,int end){
        lines.insert({start,1});
        lines.insert({end,0});

        int ans=0 , cur=0;
        for(auto &p:lines){
            if(p.second==1) cur++ , ans=max(ans,cur);
            else cur--;
        }

        return ans;
    }
};