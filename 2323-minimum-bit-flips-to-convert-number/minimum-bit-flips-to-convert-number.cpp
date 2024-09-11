class Solution {
public:

string decToBinary(int n){string s="";int i = 0;while (n > 0) {s =to_string(n % 2)+s;n = n / 2;i++;}return s;}

    int minBitFlips(int s, int e){
        string a=decToBinary(s);int n=a.size();
        string b=decToBinary(e);int m=b.size();

        cout<<a<<endl<<b;

        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());

        int dif=abs(n-m);
        if(a.size()<b.size()){
            while(dif--)a+="0";
        }
        else if(a.size()>b.size()){
            while(dif--)b+="0";
        }

        int cnt=0;
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());

        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i])cnt++;
        }

        return cnt;
    }
};