
/*
  vicky kumar
  date : 13/09/2021
  https://leetcode.com/problems/pizza-with-3n-slices/
*/


// explanation:
// we just nee to find the n/3 elements form the array such that not any two elements in the array is adjecent to each other
// note -> array is circular so, first element is adjecent element of last element and vice - versa
// so, there could be tow cases , eiter first element is taken or not 
// so solve by taking first element then -> f(0, n - 1)
// don't take first element then we have to solve for -> f(1,n)
// now take the maximum of both ->  boom !


class Solution {
public:
    
    const int inf = 1e9 + 7;
    int maxSizeSlices(vector<int>& slices) {
       // ans = max(f(1,n - 1), f(2,n)) 1 based indexing
        int n = slices.size();
        function<int(int,int,int)> solve;
        
        vector<vector<int>> dp;
        solve = [&](int i,int k,int len)->int{
            if(i >= len) return k == 0 ? 0 : -inf;
            else if(k <= 0) return 0;
            else if(dp[i][k] != -1) return dp[i][k];
            return dp[i][k] = max(slices[i] + solve(i + 2, k - 1,len), solve(i + 1, k,len));
        };
        dp.assign(n + 1, vector<int>(n/3 + 1, -1));
        int x = solve(0,n/3,n -1);
        dp.clear();
        dp.assign(n + 1, vector<int>(n / 3 + 1, -1));
        int y = solve(1,n/3,n);
        return max(x,y);
    }
};


