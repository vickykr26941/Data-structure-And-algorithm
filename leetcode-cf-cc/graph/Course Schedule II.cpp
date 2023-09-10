/*
 auther : vicky kumar
 date : 20/08/2021
 source : https://leetcode.com/problems/course-schedule-ii/
*/

// solution : first check if there cycle exists in graph then solution does not exits
// otherwise find the topological ordering of graph and return as vector 





class Solution {
public:
    vector<int> color;
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<int> in(n,0);
        
        vector<vector<int>> g(n);
        for(int i=0; i<edges.size(); i++){
            int a = edges[i][0], b = edges[i][1];
            in[a] ++;
            g[b].push_back(a);
        }
        vector<int> res;
        color.assign(n,0);
        
        
        function<int(int)> dfs;
        dfs = [&](int v){
            color[v] = 1;
            for(auto &u : g[v]){
                if(!color[u] && dfs(u)){
                    return true;
                }
                else if(color[u] == 1){
                    return true;
                }
            }
            color[v] = 2;
            return false;
        };
        
        bool ok = false;
        for(int i=0; i<n; i++){
            if(!color[i] && dfs(i)){
                ok = true;
                break;
            }
        }
        if(ok){
            return res;
        }
        
        queue<int> q;
        for(int i=0; i<n; i++){
            if(in[i] == 0){
                q.push(i);
            }
        }
        
        while(q.size() > 0){
            int from = q.front();
            q.pop();
            res.push_back(from);
            
            for(auto &to : g[from]){
                in[to] --;
                if(in[to] == 0){
                    q.push(to);
                }
            }
        }
        
        return res;
    }
};
    
// 1 - 0 - 1
// |
// 2
