/* 
 vicky kumar
 date : 13/09/2021
 https://leetcode.com/problems/path-with-minimum-effort/
*/


// hint : use bfs + biary search 
 
class Solution {
public:
    const int inf = INT_MAX;
    vector<int> dx = {-1,0,1,0};
    vector<int> dy = {0,1,0,-1};
    bool check(vector<vector<int>> &grid,int cost){
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        using pii = pair<int,int>;
        
        
        queue<pii> q;
        q.push({0,0});
        vis[0][0] = 1;
        
        while(q.size() > 0){
            auto it = q.front(); q.pop();
            int i = it.first,j = it.second;
            
            if(i == n - 1 and j == m - 1) return true;
            for(int k = 0; k < 4; k++){
                int x = i + dx[k];
                int y = j + dy[k];
                if(x >= 0 and x < n and y >=0 and y < m and !vis[x][y]){
                    if(abs(grid[x][y] - grid[i][j]) <= cost){
                        vis[x][y] = 1;
                        q.push({x,y});
                    }
                }
            }
        }
        
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        if(n == 0) return 0;
        int m = heights[0].size();
        
        int l = 0, r = 1e6 + 1;
        int ans = r;
        while(l <= r){
            int m = (l + r)/2;
            if(check(heights,m)){
                ans = m;
                r = m - 1;
            }
            else{
                l = m + 1;
            }
        }
        
    return ans;
    }
};

