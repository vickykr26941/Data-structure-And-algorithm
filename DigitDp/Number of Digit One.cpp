/*
 vicky kumar
 date : 06/07/2021
 problem : https://leetcode.com/problems/number-of-digit-one/
*/



class Solution {
public:
    
    int dp[12][2][2][12];
    int solve(string &s,int pos,int tight,int st,int cnt){
        if(pos>=s.size())
            return cnt;
        else if(dp[pos][tight][st][cnt] != -1)
            return dp[pos][tight][st][cnt];
        
        int ans = 0;
        if(st==0){
            ans += solve(s,pos + 1, 0,0,cnt);
            int en = tight?(s[pos] - '0'):9;
            for(int i=1; i<=en; i++){
                ans += solve(s,pos + 1, tight&(en==i),1,(i==1));
            }
        }
        else{
            int en = tight?(s[pos] - '0') : 9;
            for(int i=0; i<=en; i++){
                ans += solve(s,pos + 1, tight&(en==i),st,cnt+(i==1));
            }
        }
        return dp[pos][tight][st][cnt] = ans;
    }
    int countDigitOne(int n) {
        string s = to_string(n);
        
        memset(dp,-1,sizeof dp);
        return solve(s,0,1,0,0);
    }
};
