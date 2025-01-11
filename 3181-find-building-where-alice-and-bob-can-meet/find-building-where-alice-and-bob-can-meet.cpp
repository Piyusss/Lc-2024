class SegmentTree {
private:
    vector<int> tree;
    vector<int> arr;
    int n;

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = start;
        } else {
            int mid = (start + end) / 2;
            build(2 * node + 1, start, mid);
            build(2 * node + 2, mid + 1, end);

            int left = tree[2 * node + 1];
            int right = tree[2 * node + 2];
            tree[node] = (arr[left] >= arr[right]) ? left : right;
        }
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || l > end) {
            return -1;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }

        int mid = (start + end) / 2;
        int left = query(2 * node + 1, start, mid, l, r);
        int right = query(2 * node + 2, mid + 1, end, l, r);

        if (left == -1) return right;
        if (right == -1) return left;

        return (arr[left] >= arr[right]) ? left : right;
    }

    void update(int node, int start, int end, int idx, int value) {
        if (start == end) {
            arr[idx] = value;
            tree[node] = start;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(2 * node + 1, start, mid, idx, value);
            } else {
                update(2 * node + 2, mid + 1, end, idx, value);
            }

            int left = tree[2 * node + 1];
            int right = tree[2 * node + 2];
            tree[node] = (arr[left] <= arr[right]) ? left : right;
        }
    }

public:
    SegmentTree(const vector<int>& input) {
        n = input.size();
        arr = input;
        tree.resize(4 * n, 0);
        build(0, 0, n - 1);
    }

    int query(int l, int r,vector<int>& heights) {
        int x=query(0, 0, n - 1, l, r);
        return x;
    }

    void update(int idx, int value) {
        update(0, 0, n - 1, idx, value);
    }
};

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n=heights.size();

        SegmentTree t(heights);

        vector<int>res;
        for(auto &it:queries){
            int a=it[0];
            int b=it[1];

            if(a>b) swap(a,b);

            if(a==b || heights[b]>heights[a]){
                res.push_back(b);continue;
            }

            int l=b+1;
            int r=n-1;
            int temp=INT_MAX;
            while(l<=r){
                int mid=l+(r-l)/2;
                int buildingIdx=t.query(l,mid,heights);

                if(heights[buildingIdx]>heights[a] && heights[buildingIdx]>heights[b]){
                    temp=min(temp,buildingIdx);
                    r=mid-1;
                }
                else l=mid+1;
            }
            res.push_back(temp==INT_MAX ? -1 : temp);
        }

        return res;
    }
};