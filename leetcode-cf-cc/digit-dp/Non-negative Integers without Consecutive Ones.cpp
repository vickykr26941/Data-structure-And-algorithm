/*
  vicky kumar
  date : 06/07/2021
  problem : https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/
*/

   // convert the N to binary string the solve 
   // using digit dp , 
   // to maek sure there is no two consecutive one's use prev to see the previouse inserted digit


 
class Solution {
public:
    
    int dp[32][2][2][2];
    int solve(string &s,int pos,int tight,int st,int prev){
        if(pos == s.size()) return 1;
        else if(dp[pos][tight][st][prev] != -1)
            return dp[pos][tight][st][prev];
        
        int ans = 0;
        if(st == 0){
            ans += solve(s,pos+1,0,0,0);
            ans += solve(s,pos+1,tight&(s[pos]=='1'),1,1);
        }
        else{
            int en = tight?(s[pos] - '0') : 1;
            for(int i=0; i<=en; i++){
                if(prev==1 && i==1) continue;
                ans += solve(s,pos+1,tight&(en==i),st,i);
            }
        }
        return  dp[pos][tight][st][prev] = ans;
    }
    int findIntegers(int n) {
        string s = bitset<32>(n).to_string();
        for(int i=0; i<s.size(); i++){
            if(s[i]=='1'){
                s = s.substr(i);
                break;
            }
        }
        
        
        memset(dp,-1,sizeof dp);
        return solve(s,0,1,0,0);
    }
};
