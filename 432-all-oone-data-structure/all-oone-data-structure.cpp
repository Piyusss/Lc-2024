class AllOne {
public:

    set<pair<int,string>>st;
    unordered_map<string,int>mp;

    AllOne() {
        
    }
    
    void inc(string key) {
        mp[key]++;
        st.erase({mp[key]-1,key});
        st.insert({mp[key],key});
    }
    
    void dec(string key) {
        mp[key]--;
        if(mp[key]==0){
            st.erase({mp[key]+1,key});
            mp.erase(key);
        }
        else{
            st.erase({mp[key]+1,key});
            st.insert({mp[key],key});
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