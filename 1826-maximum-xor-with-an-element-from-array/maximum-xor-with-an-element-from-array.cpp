struct Node {
    Node* links[2]; 
    
    bool containsKey(int bit) {
        return (links[bit] != NULL); 
    }

    Node* get(int bit) {
        return links[bit]; 
    }

    void put(int bit, Node* node) {
        links[bit] = node; 
    }
};

class Trie {
private: Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(int num) {
        Node* node = root; 
        for (int i = 31; i >= 0; i--) { 
            int bit = (num >> i) & 1; 
            if (!node->containsKey(bit)) { 
                node->put(bit, new Node()); 
            }
            node = node->get(bit); 
        }
    }

    int getMax(int num) {
        Node* node = root;
        
        int maxNum=0; 
        for (int i = 31; i >= 0; i--) { 
            int bit = (num >> i) & 1; 

            if (node->containsKey(!bit)) { 
                maxNum |= (1 << i); 
                node = node->get(!bit);
            } else {
                node = node->get(bit);
            }
        }
        
        return maxNum; 
    }
};


class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int q=queries.size();

        vector<pair<int,pair<int,int>>>tweries;
        for(int i=0;i<q;i+=1){
            int xi=queries[i][0];
            int mi=queries[i][1];
            tweries.push_back({mi,{xi,i}});
        }

        sort(tweries.begin(),tweries.end());
        sort(nums.begin(),nums.end());

        Trie trie;
        vector<int>res(q,0);
        int i=0;

        for(auto &it:tweries){
            int mi=it.first;
            int xi=it.second.first;
            int idx=it.second.second;

            while(i<n && nums[i]<=mi){
                trie.insert(nums[i]);
                i+=1;
            }

            if(i==0) res[idx]=-1;
            else res[idx]=trie.getMax(xi);
        }

        return res;

    }
};