class Solution {
public:
    string addBinary(string a, string b){
        int n=a.size();
        int m=b.size();

        vector<int>sums(max(n,m)+1,0);
        int k=sums.size();

        int i=n-1,j=m-1,carry=0;
        string res="";

        while(i>=0 || j>=0){
            int up=0,down=0;
            if(i>=0) up=stoi(a.substr(i,1));
            if(j>=0) down=stoi(b.substr(j,1));

            int num= up + down + carry;
            if(num>=2){
                res+=to_string(num-2);
                carry=1;
            }
            else if(num==1){
                res+="1";
                carry=0;
            }
            else{
                res+="0";
                carry=0;
            }

            i--;
            j--;

        }

        if(carry) res+="1";
        reverse(res.begin(),res.end());

        return res;

    }
};