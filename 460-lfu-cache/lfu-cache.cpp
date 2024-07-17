class LFUCache {
public:

int n;
int size;

unordered_map<int,list<vector<int>>::iterator>mp; // key->address
map<int,list<vector<int>>>freq; //counter->key,value,counter

    LFUCache(int capacity) {
        n=capacity;
        size=0;
    }

    void make_most_freq_used(int key){
        auto &vec=(*(mp[key]));
        int value=vec[1];
        int counter=vec[2];
        freq[counter].erase(mp[key]);

        if(freq[counter].empty())freq.erase(counter);
        counter++;
        freq[counter].push_front({key,value,counter});
        mp[key]=freq[counter].begin();
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())return -1;
        auto vec=(*(mp[key])); // key,value,counter
        int value=vec[1];
        make_most_freq_used(key);
        return value;
    }
    
    void put(int key, int value) {
        if(n==0)return;

        if(mp.find(key)!=mp.end()){
            auto &vec=(*(mp[key]));
            vec[1]=value;
            make_most_freq_used(key);
        }
        else{
            if(size<n){
                size++;
                freq[1].push_front({key,value,1});
                mp[key]=freq[1].begin();
            }
            else{
                auto &present_list=freq.begin()->second;
                int key_to_del=(present_list.back())[0];
                present_list.pop_back();
                if(present_list.empty())freq.erase(freq.begin()->first);
                freq[1].push_front({key,value,1});
                mp.erase(key_to_del);
                mp[key]=freq[1].begin();
            }
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */