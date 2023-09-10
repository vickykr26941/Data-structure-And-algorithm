       // https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/



class Solution {
public:
    const int inf = 1e9 + 7;
    int minimumMountainRemovals(vector<int>& arr) {
        
           // time complexity O(nlogn)
//         int n = arr.size();
//         vector<int> l,r,dp(n,0);
//         for(int i=0; i<n; i++){
//             auto it = lower_bound(begin(l),end(l),arr[i]);
//             if(it==end(l))
//                 l.push_back(arr[i]);
//             else *it = arr[i];
//             dp[i] = l.size();
//         }
        
//         int ans = inf;
//         for(int i=n-1; i>=0; i--){
//             auto it = lower_bound(begin(r),end(r),arr[i]);
//             if(it==end(r))
//                 r.push_back(arr[i]);
//             else *it = arr[i];
//             if(dp[i]>1 && r.size()>1){
//                 int val = n - dp[i] - r.size() + 1;
//                 ans = min(ans,val);
//             }
//         }
//     return ans;
        
        
        
        
        // O(n^2) time complexity 
        int n = arr.size();
        vector<int> left(n,1),right(n,1);
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(arr[i] > arr[j])
                    left[i] = max(left[i], left[j] + 1);
            }
        }
        
        reverse(begin(arr),end(arr));
        for(int i=0;i<n; i++){
            for(int j=0; j<i; j++){
                if(arr[i] > arr[j])
                    right[i] = max(right[i],right[j] + 1);
            }
        }
        
        reverse(begin(right),end(right));
        int ans = inf;
        for(int i=0; i<n; i++){
            if(left[i]>1 && right[i]>1){
                int val = n - left[i] - right[i]  + 1;
                ans = min(ans, val);
            }
        }
        
        return ans;
    }
};
