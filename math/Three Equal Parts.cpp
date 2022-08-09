/* 
   auther : vicky kumar
   date : 07/07/2021
   problem : https://leetcode.com/problems/three-equal-parts/
*/



class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int n = arr.size();
        int cnt_one = 0;
        for(int i=0; i<n; i++) 
            if(arr[i] == 1) cnt_one ++;
        
        
        if(cnt_one == 0) return {0,n-1};
        if((cnt_one % 3) != 0) return {-1,-1};
        int need = cnt_one /3;
        int left = -1, mid = -1, right = -1;
        
        
        // find the first chunk
        cnt_one = 0;
        int i = 0;
        while( i < n){
            if(arr[i]==1){
                if(left== -1)
                    left = i;
                cnt_one ++;
            }
            if(cnt_one == need)
                break;
            i++;
        }
        cnt_one = 0;
        i++;
        while(i < n){
            if(arr[i]==1){
                if(mid == -1)
                    mid = i;
                cnt_one++;
            }
            if(cnt_one == need) break;
            i++;
        }
        
        cnt_one = 0;
        i++;
        while(i < n){
            if(arr[i]==1) {
                if(right == -1)
                    right = i;
                cnt_one ++;
            }
            if(cnt_one == need) break;
            i++;
        }
        
        while( right < n && arr[left]==arr[mid] && arr[mid]==arr[right] && arr[left]==arr[right])
            left++,mid++,right++;
        if(right != n) return {-1,-1};
        
        return {left-1,mid};
    }
};


