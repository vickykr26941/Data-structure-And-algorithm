/*
   vicky kumar
   date : 05-07-2021
   source : https://leetcode.com/problems/numbers-at-most-n-given-digit-set/
 */
 
class Solution {
public:
    
    int dp[12][2][2];
    int solve(vector<int> &v,int pos,int tight,int st,string &s){
        if(pos == s.size()) return 1;
        else if(dp[pos][tight][st] != -1)
            return dp[pos][tight][st];
        
        int ans = 0;
        if(st == 0){
            int en = tight?(s[pos] - '0') : 9;
            ans = solve(v,pos + 1,0,0,s);
            for(int i=0; i<v.size(); i++){
                if(v[i] > en) continue;
                ans += solve(v,pos + 1, tight&(en==v[i]),1,s);
            }
        }
        else{
            int en = tight?(s[pos] - '0') : 9;
            for(int i=0; i<v.size(); i++){
                if(v[i] > en) continue;
                ans += solve(v,pos + 1,tight&(en==v[i]),st,s);
            }
        }
        return dp[pos][tight][st] = ans;
    }
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string s = to_string(n);
        vector<int> v(digits.size(),0);
        for(int i=0; i<digits.size(); i++){
            char ch = digits[i][0];
            v[i] = ch - '0';
        }
        
        memset(dp,-1,sizeof dp);
        
        
            // subtract one because 0 is also counted in result 
        return solve(v,0,1,0,s) - 1;
    }
};


