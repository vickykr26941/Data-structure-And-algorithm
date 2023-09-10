/*
  vicky kumar
  date : 06-07-2021
  problem : https://leetcode.com/problems/numbers-with-repeated-digits/
  
 */
 


class Solution {
public:
    
    int dp[12][2][2][1<<11][2];
    int solve(string &s,int pos,int tight,int st,int cnt, int oh){
        if(pos >= s.size())
            return oh == 1;
        else if(dp[pos][tight][st][cnt][oh] != -1)
            return dp[pos][tight][st][cnt][oh];
        
        int ans = 0;
        
        if(st == 0){
            ans += solve(s,pos+1,0,st,cnt,oh);
            int en = tight ?(s[pos] - '0'): 9;
            for(int i=1; i<=en; i++){
                ans += solve(s,pos + 1, tight&(en==i),1,cnt|(1<<i),0);
            }
        }
        else{
            int en = tight ? (s[pos] - '0') : 9;
            for(int i=0; i<=en; i++){
                ans += solve(s,pos+1,tight&(en==i),st,cnt|(1<<i),oh|((cnt&(1<<i)) > 0));
            }
        }
        return dp[pos][tight][st][cnt][oh]=ans;
    }
    int numDupDigitsAtMostN(int n) {
    
        string s = to_string(n);
        memset(dp,-1,sizeof dp);
        return solve(s,0,1,0,0,0);
    }
};
