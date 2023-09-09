
// leetcode .... date : 09/09/2023
// note : dijkestra with 2D distance matrics
// url : https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/submissions/

class Solution {
public:
  

    const int inf = 1e9 + 7;

    bool valid(int x, int y, int n, int m){

        return (x >= 0 && y >= 0 && x < n && y < m);
    }
    int minimumObstacles(vector<vector<int>>& grid) {

        int n = grid.size(), m = grid[0].size();

        // auto dijkestra = [&](){

            using pii = pair<int, pair<int, int>>;
            vector<vector<int>> dist(n, vector<int>(m, inf));
            priority_queue<pii, vector<pii> , greater<pii>> q;

            q.push({0, {0, 0}});
            dist[0][0] = 0;

            while(q.size() > 0){
                int len = q.top().first, x = q.top().second.first, y = q.top().second.second;
                q.pop();
                if(x == n - 1 && y == m - 1) return len;

                for(int i = -1; i <= 1; i ++){
                    for(int j = -1; j <= 1; j ++){
                        if(abs(i) == abs(j)) continue;
                        int x_ = x + i, y_ = y + j;
                        if(!valid(x_, y_, n, m)) continue;

                        if(dist[x_][y_] > grid[x_][y_] + len){
                            dist[x_][y_] = grid[x_][y_] + len;
                            q.push({dist[x_][y_], {x_, y_}});
                        }
                    }
                }
            }
        // };

        // dijkestra();

        return -1;
    }
};
