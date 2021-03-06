/*
   vicky kumar
   date : 11/08/2021
   source : https://leetcode.com/problems/maximum-number-of-consecutive-values-you-can-make/
*/


explanation : if we can make x then their must have values v <= x now we can make all the values between x and v + x
so it make sense to sort the array first then process the array to get the desired result 
for more clerification look to the image : (https://assets.leetcode.com/users/images/f1280227-dec4-4514-ab56-e68b15b5bf7b_1616257807.8662581.png)

class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        int n = coins.size();
        sort(begin(coins),end(coins));
        int ans = 1;
        
        for(int i=0; i<n; i++){
            if(coins[i] > ans){
                return ans;
            }
        ans += coins[i];
        }
        
    return ans;
    }
};
