int n;
int dp[301];

struct Node {
    Node* links[26];
    int cntEndWith = 0;
    int cntPrefix = 0;
    bool flag = false;

    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL); 
    }

    Node* get(char ch) {
        return links[ch - 'a']; 
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }

};

class Trie {
public:
    Node* root; 

public:
    Trie() {
        root = new Node(); 
    }

    void insert(string word) {
        Node* node = root; 
        for (int i = 0; i < word.size(); i++) { 
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node()); 
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool search(string word){
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    int findLen(string &tar){
        Node* rooted=root;
        int cnt=0;
        for(int i=0;i<tar.size() && rooted!=NULL;i+=1){
            if(rooted->containsKey(tar[i])){
                cnt += 1;
                rooted=rooted->get(tar[i]);
            }
            else break;
        }
        return cnt;
    }

    bool f(unordered_set<string>&st,string &s,int idx){
        if(idx==n) return 1;
        if(idx>n) return 0;

        if(dp[idx]!=-1) return dp[idx];

        bool res=0;
        string remTar=s.substr(idx);
        int lenInTrie=findLen(remTar);

        for(int i=1;i<=lenInTrie;i+=1){
            string wait=s.substr(idx,i);
            if(!search(wait)) continue;
            bool nextRec=f(st,s,idx+i);
            if(nextRec) return 1;
        }
        return dp[idx] = 0;
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict){
        n=s.size();
        unordered_set<string>st(wordDict.begin(),wordDict.end());

        Trie trie;
        memset(dp,-1,sizeof(dp));
        for(auto &it:st) trie.insert(it);

        return trie.f(st,s,0);

    }
};