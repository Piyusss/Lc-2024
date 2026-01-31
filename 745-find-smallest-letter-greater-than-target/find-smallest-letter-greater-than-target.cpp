class Solution {
public:

bool f(int mid,vector<char>&letters,int target){
    if(letters[mid]>target) return 1;
    return 0;
}
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();

        //method-01 ---> o(n)
        // for(int i=0;i<n;i++) if(letters[i]>target) return letters[i];
        // return letters[0];

        //method-02 ---> o(log(n))
        if(target>=letters[n-1]) return letters[0];
        int l=0,r=n-1,mid=-1,ans=-1;

        while(l<=r){
            mid=l+((r-l)>>1);
            if(f(mid,letters,target)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }

        return letters[ans];
    }
};