// Given a string s and an integer k, return true if s is a k-palindrome.

// A string is k-palindrome if it can be transformed into a palindrome by removing at most k characters from it.

 

// Example 1:

// Input: s = "abcdeca", k = 2
// Output: true
// Explanation: Remove 'b' and 'e' characters.
// Example 2:

// Input: s = "abbababa", k = 1
// Output: true
 

// Constraints:

//   1 <= s.length <= 1000
//   s consists of only lowercase English letters.
//   1 <= k <= s.length
// { Driver Code Starts
// Initial Template for C++





#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    
    // // time complexity n * n * k : time limit exceede / coz expected time is  max up to n * n
    // vector<vector<vector<int>>> dp;
    // int solve(string &s, int i, int j, int k){
    //     if(i > j) return 0;
    //     if(i == j) return 1;
        
    //     if(dp[i][j][k] != -1)  return dp[i][j][k];
        
    //     int ans = 0;
    //     if(s[i] == s[j]) 
    //         ans |= solve(s, i + 1, j - 1, k);
    //     else{
    //         if(k > 0){
    //             ans |= solve(s, i + 1, j, k - 1) || solve(s, i, j - 1, k - 1);
    //         }
    //     }
    //     return ans;
    // }
    // int kPalindrome(string str, int n, int k){
        
    //     dp.clear();
    //     dp = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(n + 1, vector<int>(k + 1, -1)));
    //     return solve(str, 0, n - 1, k);
    // }
    
    
    
    int kPalindrome(string s, int n, int k){
        // idea fine the longest common subsequence in x, y where x = str, y = reverse(str)
        // ans = n - lcs(x, y) <= k ? 1 : 0;  think it it's simeple intuation ? 
        
        string t = s;
        reverse(begin(t), end(t));
        
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(s[i - 1] == t[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return (n - dp[n][n]) <= k ? 1 : 0;
        
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.kPalindrome(str, n, k)<<endl;
    }
    return 0;
}
