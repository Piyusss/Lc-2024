class SegmentTree {
private:
    vector<int> tree;
    vector<int> arr;
    int n;

    void build(int node, int start, int end) {
        if (start == end) {
            if(start!=0 && start!=n-1){
                if(arr[start] > arr[start-1] && arr[start] > arr[start+1]){
                    tree[node]=1;
                }
                else tree[node]=0;
            }
            else tree[node]=0;
        } else {
            int mid = (start + end) / 2;
            build(2 * node + 1, start, mid);      
            build(2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2]; 
        }
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || l > end) {
            return 0;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int left = query(2 * node + 1, start, mid, l, r);
        int right = query(2 * node + 2, mid + 1, end, l, r);
        return left + right;
    }

    void update(int node, int start, int end, int idx) {
        if (start == end) {
            if(start!=0 && start!=n-1){
                if(arr[start] > arr[start-1] && arr[start] > arr[start+1]){
                    tree[node]=1;
                }
                else tree[node]=0;
            }
            else tree[node]=0;
        }else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(2 * node + 1, start, mid, idx);
            } else {
                update(2 * node + 2, mid + 1, end, idx);
            }
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

public:
    SegmentTree(const vector<int>& input) {
        n = input.size();
        arr = input;
        tree.resize(4 * n, 0);
        build(0, 0, n - 1);
    }

    int query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }

    void update(int idx, int value) {
        arr[idx]=value;
        update(0, 0, n - 1, idx);
    }
    void update2(int idx) {
        update(0, 0, n - 1, idx);
    }
};

class Solution {
public:
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int m=queries.size();

        vector<int>res;
        SegmentTree t(nums);

        for(int i=0;i<m;i++){
            int type=queries[i][0];

            if(type==2){
                int idx=queries[i][1];
                int val=queries[i][2];
                t.update(idx,val);

                if(idx-1 >= 1 && idx-1 <= n-2) t.update2(idx-1);
                if(idx+1 >= 1 && idx+1 <= n-2) t.update2(idx+1);
            }
            else{
                int li=queries[i][1];
                int ri=queries[i][2];
                res.push_back(t.query(li+1,ri-1));
            }
        }

        return res;
    }
};