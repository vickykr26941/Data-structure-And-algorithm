/*
  vicky kumar
  date : 22/07/2021
  source : https://leetcode.com/problems/decode-ways-ii
 
*/




// possible choices 

// if(s[n-1] == '*'){
//     ..........* (s[n-1] == '*')
//        ans += 9 * ways(n - 1);
//     .........1* (s[n-1]=='*' && s[n-2]=='1')
//        ans += 9 * ways(n - 2)
//     .........2*     (s[n-1]=='*' && s[n-2]=='2')
//        ans += 6 * ways(n - 2)
//     .........**  (s[n-1]=='*' && s[n-2]=='*')
//        ans += 15 * ways(n - 2);
// }
// else{
//     // configure same as above 
// }



class Solution {
public:
    
    
    vector<int> dp;
    const int mod = 1e9 + 7;
    long solve(string &s,int n){
        if(n <=0 ) return 1;
        else if(dp[n] != -1)
            return dp[n];
        
        long ans = 0;
        
        if(s[n-1]=='*'){
            ans = (ans + 9 * solve(s,n-1)) %mod;
            if(n-2>=0 && s[n-2] == '1')
                ans = (ans + 9 * solve(s,n - 2)) %mod;
            if(n-2>=0 && s[n-2] == '2')
                ans = (ans + 6 * solve(s,n - 2)) %mod;
            if(n-2 >=0 && s[n-2] =='*')
                ans = (ans + 15 * solve(s,n-2)) %mod;
        }
        else{
            ans = s[n-1] !='0'? solve(s,n-1) : 0;
            ans %= mod;
            if(n-2>=0 && (s[n-2] =='1' or (s[n-2]=='2' && s[n-1]<'7'))){
                ans = (ans + solve(s,n-2)) %mod;
            }
            if(n-2>=0 && s[n-2]=='*'){
                if(s[n-1]<='6'){
                    ans = (ans + 2 * solve(s,n-2)) %mod;
                }
                else{
                    ans = (ans + solve(s,n-2)) %mod;
                }
            }
        }
        return dp[n] = ans;
    }
    int numDecodings(string s) {
        
        int n = s.size();
        dp.assign(n+1,-1);
        return (int)solve(s,s.size());
    }
};


   
