  // https://leetcode.com/problems/trapping-rain-water/submissions/

// using stack

class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        stack<int> stk;
        
        int total_water = 0;
        for(int right=0; right<n; right++){
            while(!stk.empty() && arr[stk.top()]<arr[right]){
                int buttom = stk.top(); stk.pop();
                if(stk.empty())
                    break;
                int left = stk.top();
                int cur_water = (right - left -1) * (min(arr[left],arr[right]) - arr[buttom]);
                total_water +=cur_water;
            }
            stk.push(right);
        }
    return total_water;
    }
};


   //usin dynamic programming
class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        if(n==0)
            return 0;
        vector<int> left(n,0),right(n,0);
        left[0] = arr[0];
        for(int i=1; i<n; i++){
            left[i] = max(arr[i],left[i-1]);
        }
        right[n-1] = arr[n-1];
        for(int i=n-2; i>=0; i--){
            right[i] = max(arr[i],right[i+1]);
        }
        
        int res = 0;
        for(int i=0; i<n; i++){
            res +=min(left[i],right[i]) - arr[i];
        }
        
    return res;
    }
};



// two pointer approach 
class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        int ans = 0,right_max = 0,left_max = 0, left =0,right =arr.size()-1;
        while(left<right){
            if(arr[left]<arr[right]){
                arr[left]>left_max?(left_max = arr[left]):(ans +=left_max - arr[left]);
                left++;
            }
            else{
                arr[right]>=right_max?(right_max = arr[right]):(ans +=right_max - arr[right]);
                right--;
            }
        }  
    return ans;
    }
};
