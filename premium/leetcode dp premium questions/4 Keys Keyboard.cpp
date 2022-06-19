// Imagine you have a special keyboard with the following keys:
//     A: Print one 'A' on the screen.
//     Ctrl-A: Select the whole screen.
//     Ctrl-C: Copy selection to buffer.
//     Ctrl-V: Print buffer on screen appending it after what has already been printed.
// Given an integer n, return the maximum number of 'A' you can print on the screen with at most n presses on the keys.

 

// Example 1:

// Input: n = 3
// Output: 3
// Explanation: We can at most get 3 A's on screen by pressing the following key sequence:
// A, A, A
// Example 2:

// Input: n = 7
// Output: 9
// Explanation: We can at most get 9 A's on screen by pressing following key sequence:
// A, A, A, Ctrl A, Ctrl C, Ctrl V, Ctrl V
 

// Constraints:

// 1 <= n <= 50


 
 // brute force algorithms

// class Solution {
// public:

//     int solve(int n,int a_num, int copy){
//         if(n <= 0) return a_num;
//         int x = solve(n - 1, a_num + 1, copy);
//         int y = solve(n - 1, a_num + copy, copy);
//         int z = solve(n - 2, a_num, a_num);
//         return max({x, y, z});
//     }
//     int maxA(int n) {
//        return solve(n, 0, 0);
//     }
// };


class Solution {
public:

    
    int maxA(int n) {
       
       int dp[52];
       dp[0] = 0;
       for(int i = 1; i <= n; i++){
           dp[i] = dp[i - 1] + 1;
           for(int j = 2; j < i; j++){
               dp[i] = max(dp[i], dp[j - 2] * (i - j + 1));
           }
       }
       return dp[n];
    }
};

  
 
