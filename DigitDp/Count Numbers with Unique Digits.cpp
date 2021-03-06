/*
 vicky kumar
 date : 06/07/2021
 problem : https://leetcode.com/problems/count-numbers-with-unique-digits/

*/

class Solution {
public:
    
    int dp[12][2][2][1<<11][2];
    int solve(string &s,int pos,int tight,int st,int taken,int cnt){
        if(pos >= s.size()) return cnt==1;
        else if(dp[pos][tight][st][taken][cnt] != -1)
            return dp[pos][tight][st][taken][cnt];
        
        int ans = 0;
        if(st == 0){
            ans += solve(s,pos+1,0,0,taken,cnt);
            int en = tight?(s[pos] - '0') : 9;
            for(int i=1; i<=en; i++){
                ans += solve(s,pos + 1, tight&(en==i),1,taken|(1<<i),1);
            }
        }
        else{
            int en = tight?(s[pos] - '0') : 9;
            for(int i=0; i<=en; i++){
                ans += solve(s,pos+1,tight&(en==i),st,taken|(1<<i),cnt&((taken&(1<<i))==0));
            }
        }
        
        return dp[pos][tight][st][taken][cnt] = ans;
    }
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;
        else if(n==1) return 10;
        
        int val = pow(10,n);
        string s = to_string(val);
        
        memset(dp,-1,sizeof dp);
        return solve(s,0,1,0,0,0) + 1;
    }
};




// combination solution (math)
// we can place values like this permutation without repetition 
// _ __ _ __ // 9 9 8 7 6 ........ 

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int val = 1,ans = 0;
        if(n==0) return val;
        else if(n==1) return 10;
        else if(n==2) return 91;
        else{
            val = 9 * 9;
            ans +=91;
            n-=2;
            int x = 8;
            while(n>0){
                val *=x;
                ans += val;
                n--;
                x--;
            }
            // ans+=val;
        }
    return ans;
    }
};

