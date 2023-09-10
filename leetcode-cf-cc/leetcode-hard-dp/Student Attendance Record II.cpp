/*
 vicky kumar
 date : 15/08/2021
 problem : https://leetcode.com/problems/student-attendance-record-ii/
*/
explanation : f(i,Absunt_cnt,prevL,curL) 
    at ith location we can put P(present) then f(i+1,A,0,0)
    at ith location we can put A(absunt) then f(i+1,A-1,0,0) , this operation can be allowed only once 
    at ith location we can put L(late) the f(i+1,A,1,0) 
    at ith location we can put L(late ) if previous L is true then f(i+1,A,1,1)
    
    if two consecutive late (x && y) then we have only two choice either A, or P then f(i+1,A-1,0,0) + f(i+1,A,0,0)  
    ans = addition of all 
    
  
class Solution {
public:
    
    const int mod = 1e9 + 7;
    int N;
    int dp[100005][2][2][2];
    int solve(int i,int A,int x,int y){
        if(i>=N && A>=0)
            return 1;
        if(A < 0) return 0;
        else if(dp[i][A][x][y] != -1)
            return dp[i][A][x][y];
        
        long long ans = 0;
        // if(x && y){
        //     ans = (ans + solve(i+1,A,0,0))%mod;
        //     ans = (ans + solve(i+1,A-1,0,0))%mod;
        // }
        // else{
        //     ans = (ans + solve(i+1,A,0,0)) %mod;
        //     ans = (ans + solve(i+1,A-1,0,0)) % mod;
        //     if(!x)
        //        ans = (ans + solve(i+1,A,1,y)) % mod;
        //     if(x && !y){
        //         ans = (ans + solve(i+1,A,1,1)) %mod;
        //     }
        // }
        
        
          // with few lines of code 
          ans = (ans + solve(i+1,A,0,0))%mod;
          ans = (ans + solve(i+1,A-1,0,0))%mod;
          if(!x){
              ans = (ans + solve(i+1,A,1,y)) % mod;
          }
          if(x && !y){
              ans = (ans + solve(i+1,A,1,1)) %mod;
          }
      return dp[i][A][x][y] = (int)ans%mod;
    }
    int checkRecord(int n) {
        N = n;
        
        memset(dp,-1,sizeof(dp));
        return solve(0,1,0,0);
    }
};
