/ *
 auther : vicky kumar
 date : 20/08/2021
 sourc : https://leetcode.com/problems/course-schedule/
*/


 // find the topological sort, if topological sort exists then yes otherwise no
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<int> in(n,0);
        
        vector<vector<int>> g(n);
        for(int i=0; i<edges.size(); i++){
            int a = edges[i][0], b = edges[i][1];
            in[b]++;
            g[a].push_back(b);
        }
        queue<int> q;
        for(int i=0; i<n; i++){
            if(in[i] == 0){
                q.push(i);
            }
        }
        vector<int> order;
        while(q.size() > 0){
            int node = q.front();
            q.pop();
            order.push_back(node);
            for(auto &to : g[node]){
                in[to] --;
                if(in[to] == 0){
                    q.push(to);
                }
            }
        }
    return order.size() == n;
    }
};



 // build the directed graph and check if there cycle exists or not 
class Solution {
public:
    vector<vector<int>> g;
    vector<int> color;
    bool dfs(int v){
        color[v] = 1;
        for(auto &u : g[v]){
            if(!color[u]){
                if(dfs(u)) return true;
            }
            else if(color[u] == 1){
                return true;
            }
        }
        color[v] = 2;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& edges) {
        g.resize(n);
        for(int i=0; i<edges.size(); i++){
            int a = edges[i][0], b = edges[i][1];
            g[a].push_back(b);
        }
        
        color.assign(n,0);
        for(int i=0; i<n; i++){
            if(!color[i] && dfs(i))
                return false;
        }
    return true;
    }
};





