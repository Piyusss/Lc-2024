class Solution {
public:
        struct trieNode{
            int idx;
            trieNode* child[26];
          };

          trieNode* getNode(int i){
            trieNode* temp=new trieNode();
            temp->idx=i;

            for(int i=0;i<26;i++){
                temp->child[i]=NULL;
            }
            return temp;
        }

        void insertTrie(trieNode* crawl,int i,vector<string>& wordsContainer){
            string word=wordsContainer[i];
            int n=word.size();

            for(int j=n-1;j>=0;j--){
                int ch_idx=word[j]-'a';

                if(crawl->child[ch_idx]==NULL){
                    crawl->child[ch_idx]=getNode(i);
                }
                crawl=crawl->child[ch_idx];
                if(wordsContainer[crawl->idx].size()>n){
                    crawl->idx=i;
                }
            }
        }

        int searchTrie(trieNode* crawl,string &word){
            int n=word.size();
            int result_idx=crawl->idx;

            for(int i=n-1;i>=0;i--){
                int ch_idx=word[i]-'a';
                crawl=crawl->child[ch_idx];
                if(crawl==NULL)return result_idx;
                result_idx=crawl->idx;
            }
            return result_idx;
    }

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery){
        int n=wordsContainer.size();
        int m=wordsQuery.size();

        trieNode* root=getNode(0);

        vector<int>ans;

        for(int i=0;i<n;i++){
            if(wordsContainer[root->idx].size()>wordsContainer[i].size()){
                root->idx=i;
            }
            insertTrie(root,i,wordsContainer);
        }

        for(int i=0;i<m;i++){
            ans.push_back(searchTrie(root,wordsQuery[i]));
        }
        return ans;
    }
};