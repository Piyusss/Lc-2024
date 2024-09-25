class TrieNode {
public:
    TrieNode* children[26]; 
    int count; 

    TrieNode(){
        count=0;
        for(int i=0;i<26;i++) {
            children[i]=NULL;
        }
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words){
        TrieNode* root=new TrieNode();

        for(auto &word:words){
            TrieNode* node=root;
            for(char &c:word){
                int idx=c-'a';
                if(node->children[idx]==NULL) {
                    node->children[idx]=new TrieNode();
                }
                node=node->children[idx];
                node->count++; 
            }
        }

        vector<int>ans;
        for(auto &word:words){
            TrieNode* node=root;
            int score=0;
            for(char &c:word){
                int idx=c-'a';
                node=node->children[idx];
                score+=node->count; 
            }
            ans.push_back(score);
        }

        return ans;

    }
};
