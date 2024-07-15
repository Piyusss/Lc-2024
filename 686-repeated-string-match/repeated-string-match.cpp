class Solution {
public:
    void computeLps(string& s,vector<int>& lps){
        int n=s.size();
        int len=0;  
        int i=1;
        while(i<n){
            if(s[i]==s[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len!=0)len=lps[len-1];
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
    }

    vector <int> search(string txt, string pat)
        {
            int m=pat.size();
            int n=txt.size();
            
            vector<int>lps(m);
            computeLps(pat,lps);
            
            int i=0,j=0;
            vector<int>result;
            
            while(i<n){
                if(txt[i]==pat[j]){i++;j++;}
                if(j==m){
                    result.push_back(i-m+1);
                    j=lps[j-1];
                }
                else if(txt[i]!=pat[j]){
                    if(j!=0)j=lps[j-1];
                    else i++;
                }
        }
        return result;
    }

    int repeatedStringMatch(string pat, string b){
        if(pat==b)return 1;

        int n=pat.size();
        int m=b.size();


        string temp=pat;
        int cnt=1;
        while(temp.size()<m){
            temp+=pat;
            cnt++;
        }

        vector<int>hold1=search(temp,b);
        if(hold1.size()>0)return cnt;

        vector<int>hold2=search(temp+pat,b);
        if(hold2.size()>0)return cnt+1;

        return -1;
    }
};