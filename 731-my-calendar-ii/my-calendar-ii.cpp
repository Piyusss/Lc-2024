class MyCalendarTwo {
public:
    set<pair<int,int>>st;

    MyCalendarTwo() {
        
    }

    vector<pair<int,int>>v;
    bool book(int start, int end){
        for(int i=0;i<v.size();i++){
            for(int j=i+1;j<v.size();j++){
                if(start<v[i].second && end>v[i].first && start<v[j].second && end>v[j].first && v[i].first<v[j].second && v[i].second>v[j].first)return 0;
            }
        }
        v.push_back({start,end});
        return 1;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */