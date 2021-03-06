/*
 vicky kumar
 date : 15/08/2021
 source : https://leetcode.com/problems/find-all-good-strings/
*/

class Solution {
public:
    
    vector<int> lps;
    
    const int mod = 1e9 + 7;
    int dp[505][52][3][3];
    int solve(string &s1,string&s2,string &evil,int pos,int epos,int ta,int tb){
        if(epos == evil.size()) return 0;
        if(pos == s1.size()) return 1;
        if(dp[pos][epos][ta][tb] != -1)
            return dp[pos][epos][ta][tb];
        
        int ans = 0;
        char from = ta ? s1[pos] : 'a';
        char to = tb ? s2[pos] : 'z';
        for(char c = from; c <= to; c++){
            
            int j = epos;
            while(j > 0 && evil[j] != c) j = lps[j - 1];
            if(c == evil[j]) j++;
            ans += solve(s1,s2,evil,pos+1,j,ta&(c == from) ,tb&(c == to));
            ans %= mod;
        }
        
        return dp[pos][epos][ta][tb] = ans;
    }
    int findGoodStrings(int n, string s1, string s2, string evil) {  
        int m = evil.size();
        
        lps.assign(m,0);
        for(int i=1, j = 0; i<m; i++){
            while(j > 0 && evil[i] != evil[j]) j = lps[j-1];
            if(evil[j] == evil[i])
                lps[i] = ++j;
        }
        
        memset(dp,-1,sizeof(dp));
        return solve(s1,s2,evil,0,0,1,1);
    }
};
