// Approach-01:
class Solution {
public:
    bool rotateString(string s, string goal){
        int n=s.size();
        int m=goal.size();

        if(m!=n) return 0;

        s+=s;
        if(s.find(goal) != string::npos) return 1;

        return 0;

    }
};

// Approach-02:
// class Solution {
// public:
//     bool rotateString(string s, string goal){
//         int n=s.size();
//         int m=goal.size();

//         if(m!=n) return 0;

//         s+=s;
//         for(int i=0;i<n;i++){
//             if(s.substr(i,m)==goal) return 1;
//         }

//         return 0;

//     }
// };

// Approach-03:
// class Solution {
// public:
//     bool rotateString(string s, string goal){
//         int n=s.size();
//         int m=goal.size();

//         if(m<n) return 0;

//         s+=s;
//         for(int i=0;i<n;i++){
//             if(s.substr(i,m)==goal) return 1;
//         }

//         return 0;

//     }
// };

// Approach-04:
// class Solution {
// public:
//     bool rotateString(string s, string goal) {
//         int n=s.size();

//         for(int i=0;i<n;i++){
//             rotate(s.begin(),s.begin()+1,s.end());
//             if(s==goal) return 1;
//         }

//         return 0;

//     }
// };

// Approach-05:
// class Solution {
// public:
//     bool rotateString(string s, string goal) {
//         int n=s.size();

//         for(int i=0;i<n;i++){
//             s.push_back(s[0]);
//             s.erase(0,1);
//             if(s==goal) return 1;
//         }

//         return 0;

//     }
// };