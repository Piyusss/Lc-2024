class SnapshotArray {
public:

int snap_id;
vector<vector<pair<int,int>>>v;

    SnapshotArray(int length) {
        snap_id=0;
        v.resize(length);
        for(int i=0;i<length;i++)v[i].push_back({0,0});
    }
    
    void set(int index, int val) {
        v[index].push_back({snap_id,val});
    }
    
    int snap() {
        return snap_id++;
    }
    
    int get(int index, int snap_id) {
        int l=0,r=v[index].size()-1;
        int res=0;

        while(l<=r){
            int mid=l+(r-l)/2;
            
            if(v[index][mid].first<=snap_id){
                res=v[index][mid].second;
                l=mid+1;
            }
            else r=mid-1;
        }
        
        return res;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */