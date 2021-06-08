  // https://leetcode.com/problems/closest-subsequence-sum/submissions/
  // using meet in the middle algorithm
  class Solution {
public:
    
    const int inf = 1e9 + 10;
    int minAbsDifference(vector<int>& arr, int goal) {
        int n = arr.size();
        vector<int> L = {0}, R{0};
        int l = n/2, r = n - n/2;
        for(int i=0; i<(1<<l); i++){
            int val = 0;
            for(int j=0; j<l; j++){
                if(i & (1<<j)){
                    val += arr[j];
                }
            }
            L.push_back(val);
        }
        
        for(int i=0; i<(1<<r); i++){
            int val = 0;
            for(int j=0; j<r; j++){
                if(i & (1 << j)){
                    val += arr[l + j];
                }
            }
            R.push_back(val);
        }
        
        sort(begin(R),end(R));
        int ans = abs(goal);
        for(int i = 0; i<L.size(); i++){
            int y = goal - L[i];
            int pos = lower_bound(begin(R),end(R),y) - begin(R);
            if(pos < R.size()){
                ans = min(ans, abs(goal - (L[i] + R[pos])));
                int new_pos = pos;
                new_pos ++;
                if(new_pos < R.size()){
                    ans = min(ans, abs(goal - (L[i] + R[new_pos])));
                }
            }
            if(pos>0){
                int new_pos = pos;
                new_pos --;
                ans = min(ans, abs(goal - (L[i] + R[new_pos])));
            }
        }
        
    return ans;
    }
};

// (x + y) - goal = 0
// x + y = goal
// y = goal - x
