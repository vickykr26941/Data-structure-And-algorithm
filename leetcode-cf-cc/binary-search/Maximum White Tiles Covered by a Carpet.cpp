// binary search : O(nlogn)
// date : 01/06/22 (jun 1 22)


class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        
        int n = tiles.size();
        vector<int> pref(n,0);
        sort(begin(tiles),end(tiles));
        vector<int> v(n, 0);
        for(int i = 0; i < n; i++){
            pref[i] = (tiles[i][1] - tiles[i][0] + 1);
            if(i > 0) pref[i] += pref[i - 1];
            
            v[i] = tiles[i][1];
        }
        
        
        int res = 0;
        for(int i = 0; i <(int)tiles.size(); i++){
            int start_pos = tiles[i][0], end_pos = tiles[i][0] + carpetLen - 1;
            int index = lower_bound(begin(v),end(v), end_pos) - begin(v);
            
            int cur_ans = 0;
            
            if(index == n){
                cur_ans += pref[n - 1];
                cur_ans -= i == 0 ? 0 : (pref[i - 1]);
            }else{
                cur_ans = end_pos < tiles[index][0] ? 0 : (end_pos - tiles[index][0] + 1);
                index --;
                if(index >= 0){
                    cur_ans += pref[index];
                    cur_ans -= i == 0 ? 0 : (pref[i - 1]);
                }
            }
            
            res = max(res, cur_ans);
        }
        
        return res;
        
        
    }
};
