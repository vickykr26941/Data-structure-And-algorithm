

// solution using digit dp
// time : (1 << 10) * 10 * (1 << 3)  // pow(2, 10) * 10 * pow(2, 3) // 2 ^ 13 * 10
// space : same as time

// date : 08/14/2022 14:47
// link : https://leetcode.com/problems/count-special-integers/


class Solution {
public:
    
    int dp[(1 << 10)][10][2][2][2];
    int solve(string &s, int i, int st, int tight, int mask, int ok){
        if(i >= s.size()) return ok;
        if(dp[mask][i][st][tight][ok] != -1) return dp[mask][i][st][tight][ok];
        
        
        int ans = 0;
        if(st == 0){
            int en = tight ? (s[i] - '0') : 9;
            ans += solve(s, i + 1, 0, 0, mask, ok);
            for(int j = 1; j <= en; j ++){
                ans += solve(s, i + 1, 1, tight & (en == j), mask | (1 << j), ok);
            }
        }else{
            int en = tight ? (s[i] - '0') : 9;
            for(int j = 0; j <= en; j ++){
                int t = ok;
                if((mask & (1 << j)) > 0) t = 0;
                ans += solve(s, i + 1, st, tight & (en == j), mask | (1 << j), t);
            }
        }
        return dp[mask][i][st][tight][ok] = ans;
        
    }
    int countSpecialNumbers(int n) {
        string s = to_string(n);
        
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, 0, 1, 0, 1) - 1;
    }
};
