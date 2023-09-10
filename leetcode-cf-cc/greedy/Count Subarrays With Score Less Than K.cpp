// date : 12/06/22


class Solution {
public:
    long long countSubarrays(vector<int>& arr, long long k) {
        
    
        long long s = 0, j = 0, ans = 0;
        for(int i = 0; i < (int)arr.size(); i++){
            s += arr[i];
            while(s * (i + 1 - j) >= k){
                s -= arr[j];
                j++;
            }
            ans += (i - j + 1);
        }
        return ans;
    }
};
