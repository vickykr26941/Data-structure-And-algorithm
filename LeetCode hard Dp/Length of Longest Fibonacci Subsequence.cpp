// data : Jul 26/22
// https://leetcode.com/submissions/detail/757286227/

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        
//         // time complexity : O(n * n * logn * 17)
        
//         // approach choose 2 elements and find next elements using 
//         // binary search till getting the numbers
        
        
//         int ans = 0;
//         for(int i = 0; i < n; i++){
//             for(int j = i + 1; j < n; j++){
//                 int x = arr[i], y = arr[j];
//                 int pos = j + 1;
                
//                 bool ok = true;
//                 int cnt = 0;
//                 while(ok){
//                     int l = pos, r = n - 1;
//                     int next_index = lower_bound(begin(arr) + l, end(arr), x + y) - begin(arr);
//                     if(next_index < n && arr[next_index] == (x + y)){
//                         pos = next_index + 1;
//                         x = y;
//                         y = arr[next_index];
//                     }else{
//                         ok = false;
//                         break;
//                     }
//                     cnt ++;
//                 }
//                 ans = max(ans, cnt + 2);
//             }
//         }
        
        
//         return ans >= 3 ? ans : 0;
        
        
        
        
        // brute force using set
        
        unordered_set<int> st(begin(arr) , end(arr));
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                
                int x = arr[i] , y = arr[j];
                int z = (x + y);
                int cnt = 2;
                while(st.count(z) > 0){
                    cnt ++;
                    
                    ans = max(ans, cnt);
                    x = y;
                    y = z;
                    z = (x + y);
                }
            }
        }
        
        return ans <= 2 ? 0 : ans;
    }
};
