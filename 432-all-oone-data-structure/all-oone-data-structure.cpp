class AllOne {
public:

    set<pair<int,string>>st;
    unordered_map<string,int>mp;

    AllOne() {
        
    }
    
    void inc(string key) {
        int n=mp[key];
        mp[key]++;
        st.erase({n,key});
        st.insert({n+1,key});
    }
    
    void dec(string key) {
        int n=mp[key];
        mp[key]--;
        if(mp[key]==0){
            st.erase({n,key});
            mp.erase(key);
        }
        else{
            st.erase({n,key});
            st.insert({n-1,key});
        }
    }
    
    string getMaxKey() {
        return st.size()>=1 ? st.rbegin()->second : "";
    }
    
    string getMinKey() {
        return st.size()>=1 ? st.begin()->second : "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */