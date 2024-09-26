class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    vector<pair<int,int>>v;
    bool book(int start, int end){
        for(int i=0;i<v.size();i++){
            if((start<v[i].second && end>v[i].first))return 0;
        }
        v.push_back({start,end});
        return 1;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */