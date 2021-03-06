/*
  vicky kumar
  date : 07/07/2021
  problem : https://leetcode.com/problems/minimum-distance-to-type-a-word-using-two-fingers
   
*/


class Solution {
public:
    
    const int inf = 1e9 + 7;
    
    int dp[305][27][27];
    int dist(int from,int to){
        int x1 = from/6,y1 = from%6;
        int x2 = to/6 , y2 = to%6;
        return from < 26 ? (abs(x1-x2) + abs(y1 - y2)) : 0;
    }
    int solve(string &word,int pos,int left=26,int right=26){
        if(pos >= word.size()) return 0;
        else if(dp[pos][left][right] != -1)
            return dp[pos][left][right];
        
        int to = word[pos] - 'A';
        int ans = dist(left, to) + solve(word,pos+1,to,right);
        ans = min(ans,dist(right,to) + solve(word,pos+1,left,to));
        
        return dp[pos][left][right] = ans;
    }
    int minimumDistance(string word) {
        int n = word.size();
        
        memset(dp,-1,sizeof dp);
        return solve(word,0);
    }
};

