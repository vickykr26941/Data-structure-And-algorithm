// https://leetcode.com/problems/last-day-where-you-can-still-cross/
// Last Day Where You Can Still Cross


class Solution {
public:
    
    vector<vector<int>> mat;
    int R = 0, C = 0;
    bool check(vector<vector<int>> &cells, int k){
        int n = R, m = C;
        mat.assign(n, vector<int>(m, 0));
        for(int i = 0; i < k; i ++){
            int x = cells[i][0], y = cells[i][1];
            x --, y --;
            mat[x][y] = 1;
        }
        using pii = pair<int,int>;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        queue<pii> q;
        for(int j = 0; j < m; j ++){
            if(mat[0][j] == 0){
                q.push({0, j});
                vis[0][j] = 1;
            }
        }
        
        while(q.size() > 0){
            auto  f = q.front(); q.pop();
            if(f.first == n - 1) return true;
            for(int i = -1; i <= 1; i ++){
                for(int j = -1; j <= 1; j ++){
                    if(abs(i) == abs(j)) continue;
                    
                    int x = f.first + i, y = f.second + j;
                    if(x >= 0 && y >= 0 && x < n && y < m && mat[x][y] == 0 && vis[x][y] == 0){
                        vis[x][y] = 1;
                        q.push({x, y});
                    }
                }
            }
        }
        
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        
        R = row, C = col;
        
        int l = 1, r = cells.size();
        int ans =  0;
        while(l <= r){
            int m = (l + r) / 2;
            if(check(cells, m)){
                ans = m;
                l = m + 1;
            }else{
                r = m - 1;
            }
        }
        
        return ans;
    }
};
