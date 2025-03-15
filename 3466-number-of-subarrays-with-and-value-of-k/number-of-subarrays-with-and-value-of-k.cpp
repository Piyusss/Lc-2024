using ll=long long;

class SegmentTree {
private:
    vector<int> tree;
    vector<int> arr;
    int n;

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(2 * node + 1, start, mid);      
            build(2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] & tree[2 * node + 2]; 
        }
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || l > end) {
            return ~0;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int left = query(2 * node + 1, start, mid, l, r);
        int right = query(2 * node + 2, mid + 1, end, l, r);
        return left & right;
    }

    void update(int node, int start, int end, int idx, int value) {
        if (start == end) {
            tree[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(2 * node + 1, start, mid, idx, value);
            } else {
                update(2 * node + 2, mid + 1, end, idx, value);
            }
            tree[node] = tree[2 * node + 1] & tree[2 * node + 2];
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
        update(0, 0, n - 1, idx, value);
    }
};


class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();

        SegmentTree t(nums);
        ll cnt=0;

        for(int i=0;i<n;i++){

            //first-binary-search
            int lo_1=i;
            int hi_1=n-1;
            ll candidate_1=-1;

            while(lo_1 <= hi_1){
                int mid=lo_1+((hi_1-lo_1)>>1);
                ll calcAndFromIToMidPushLeft=t.query(i,mid);

                if(calcAndFromIToMidPushLeft<k){
                    candidate_1=mid;
                    hi_1=mid-1;
                }
                else if(calcAndFromIToMidPushLeft>k){
                    lo_1=mid+1;
                }
                else{
                    candidate_1=mid;
                    hi_1=mid-1;
                }
            }

            //second-binary-search
            int lo_2=i;
            int hi_2=n-1;
            ll candidate_2=-1;

            while(lo_2 <= hi_2){
                int mid=lo_2+((hi_2-lo_2)>>1);
                ll calcAndFromIToMidPushRight=t.query(i,mid);

                if(calcAndFromIToMidPushRight<k){
                    hi_2=mid-1;
                }
                else if(calcAndFromIToMidPushRight>k){
                    candidate_2=mid;
                    lo_2=mid+1;
                }
                else{
                    candidate_2=mid;
                    lo_2=mid+1;
                }
            }

            //now
            if(candidate_1 != -1 && candidate_2 != -1) cnt += (candidate_2-candidate_1+(ll)1);
        }

        return cnt;
    }
};