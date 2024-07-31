class Solution {
public:

int dp[1000+1][1000+1];

int f(int idx,vector<vector<int>>& books,int remaining_width,int cur_height,int shelfWidth){
    if(idx>=books.size())return cur_height;

    if(dp[idx][remaining_width]!=-1)return dp[idx][remaining_width];

    int same_layer=1e9;
    int next_layer=1e9;

    if(books[idx][0]<=remaining_width)same_layer=f(idx+1,books,remaining_width-books[idx][0],max(cur_height,books[idx][1]),shelfWidth);
    next_layer=cur_height+f(idx+1,books,shelfWidth-books[idx][0],books[idx][1],shelfWidth);

    return dp[idx][remaining_width]= min(same_layer,next_layer);
}
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth){
        memset(dp,-1,sizeof(dp));
        return f(0,books,shelfWidth,books[0][1],shelfWidth);
    }
};