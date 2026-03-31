class Solution {
public:
    string generateString(string a,string b) {
        int n=a.size(),m=b.size();

        string r(n+m-1,'#');

        for(int i=0;i<n;i++){
            if(a[i]=='T'){
                for(int j=0;j<m;j++){
                    if(r[i+j]=='#') r[i+j]=b[j];
                    else if(r[i+j]!=b[j]) return "";
                }
            }
        }

        for(int i=0;i<n;i++){
            if(a[i]=='F'){
                bool ok=0;
                for(int j=0;j<m;j++){
                    if(r[i+j]=='#') continue;
                    if(r[i+j]!=b[j]){
                        ok=1;
                        break;
                    }
                }

                if(!ok){
                    for(int j=m-1;j>=0;j--){
                        if(r[i+j]!=b[j]&&b[j]!='a'){
                            if(r[i+j]=='#') r[i+j]='a';
                            ok=1;
                            break;
                        }
                    }
                }

                if(!ok){
                    for(int j=m-1;j>=0;j--){
                        if(r[i+j]!=b[j]){
                            if(r[i+j]=='#') r[i+j]=(b[j]=='a'?'b':'a');
                            ok=1;
                            break;
                        }
                    }
                }

                if(!ok) return "";
            }
        }

        for(int i=0;i<n+m-1;i++) if(r[i]=='#') r[i]='a';
        return r;
    }
};