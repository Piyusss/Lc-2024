class Solution {
public:
    struct trieNode{
        trieNode* left;
        trieNode* right;
    };
    void insert(trieNode* root,int &num){
        trieNode* crawl=root;
        for(int i=31;i>=0;i--){
            int ith_bit=(num>>i)&1;
            if(ith_bit==0){
                if(!crawl->left)crawl->left=new trieNode();
                crawl=crawl->left;
            }
            else{
                if(!crawl->right)crawl->right=new trieNode();
                crawl=crawl->right;
            }
        }
    }

    int f(trieNode* root,int &num){
        int maxi=0;
        trieNode* crawl=root;

        for(int i=31;i>=0;i--){
            int ith_bit=(num>>i)&1;
            if(ith_bit==1){
                if(crawl->left){
                    maxi+=pow(2,i);
                    crawl=crawl->left;
                }
                else{
                    crawl=crawl->right;
                }
            }
            else{
                if(crawl->right){
                    maxi+=pow(2,i);
                    crawl=crawl->right;
                }
                else{
                    crawl=crawl->left;
                }
            }
        }
        return maxi;
    }

    int findMaximumXOR(vector<int>& nums) {
        //Method-01:Brute force- O(N^2)

        //Method-02:
        int n=nums.size();
        trieNode* root=new trieNode();
        for(auto &it:nums){
            insert(root,it);
        }
        int ans=0;
        for(auto &it:nums){
            ans=max(ans,f(root,it));
        }
        return ans;
    }
};