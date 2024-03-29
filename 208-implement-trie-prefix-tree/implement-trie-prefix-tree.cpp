class Trie {
public:
struct trieNode{
    bool isEndOfWord;
    trieNode* child[26];
};

trieNode* getNode(){
    trieNode* newNode=new trieNode();
    newNode->isEndOfWord=false;
    for(int i=0;i<26;i++)
        newNode->child[i]=NULL;
    return newNode;
}
    trieNode* root;
    Trie() {
        root=getNode();
    }
    
    void insert(string word) {
        trieNode* crawl=root;
        for(int i=0;i<word.length();i++){
            char ch=word[i];
            int idx=ch-'a';

            if(crawl->child[idx]==NULL){
                crawl->child[idx]=getNode();
            }
            crawl=crawl->child[idx];
        }
        crawl->isEndOfWord=true;
    }
    
    bool search(string word) {
        trieNode* crawl=root;
        for(int i=0;i<word.length();i++){
            char ch=word[i];
            int idx=ch-'a';

            if(crawl->child[idx]==NULL){
                return 0;
            }
            crawl=crawl->child[idx];
        }
        if(crawl->isEndOfWord==true)return true;
        return 0;
    }
    
    bool startsWith(string prefix) {
        trieNode* crawl=root;
        for(int i=0;i<prefix.length();i++){
            char ch=prefix[i];
            int idx=ch-'a';

            if(crawl->child[idx]==NULL){
                return 0;
            }
            crawl=crawl->child[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */