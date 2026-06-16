class LRUCache {
public:

    int n;
    list<int>dll;
    unordered_map<int,pair<list<int>::iterator,int>>mp;
    
    LRUCache(int capacity) {
        n=capacity;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            pair<list<int>::iterator,int>p=mp[key];

            dll.erase(p.first);
            dll.push_front(key);
            mp[key].first=dll.begin();

            return p.second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            pair<list<int>::iterator,int>p=mp[key];

            dll.erase(p.first);
            dll.push_front(key);
            mp[key]={dll.begin(),value};
        }
        else{
            dll.push_front(key);
            mp[key]={dll.begin(),value};
            n--;
        }

        if(n<0){
            mp.erase(dll.back());
            dll.pop_back();
            n++;
        }
    }
};