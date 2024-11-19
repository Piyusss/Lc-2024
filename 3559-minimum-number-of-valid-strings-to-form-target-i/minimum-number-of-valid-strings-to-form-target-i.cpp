int dp[10000+1];
int n;

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

    int findPref(string &t,Node* root){
        int len=0;

        for(int i=0;i<t.size() && root!=NULL ;i+=1){
            if(root->containsKey(t[i])){
                len +=1;
                root=root->get(t[i]);
            }
            else break;
        }
        return len;
    }
    int dpWithTrie(string &t,int idx){
        if(idx==n) return 0;
        if(idx>n) return 1E4;

        if(dp[idx] != -1) return dp[idx];

        string remTar=t.substr(idx);
        int prefInTrieLen=findPref(remTar,root);

        int mini=1E4;
        for(int i=1;i<=prefInTrieLen;i+=1){
            mini=min(mini,1 + dpWithTrie(t,idx+i));
        }
        return dp[idx] = mini;
    }
};

class Solution {
public:

    int minValidStrings(vector<string>& words, string target){
        Trie trie;
        n=target.size();
        memset(dp,-1,sizeof(dp));
        for(auto &it:words) trie.insert(it);

        int res=trie.dpWithTrie(target,0);

        return res==1E4 ? -1 : res;
    }
};