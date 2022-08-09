

https://leetcode.com/problems/critical-connections-in-a-network/


class Solution {
public:
    vector<int> in,low,vis;
    vector<vector<int>> adj,res;
    
    int timer = 0;
    void dfs(int v,int par){
        vis[v] = 1;
        in[v] = low[v] = timer++;
        for(auto &u : adj[v]){
            if(u == par) continue;
            if(!vis[u]){
                dfs(u,v);
                if(low[u] > in[v])
                    res.push_back({v,u});
                low[v] = min(low[v],low[u]);
            }else{
                low[v] = min(low[v],in[u]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        in.assign(n + 1, 0);
        low.assign(n + 1, 0);
        vis.assign(n + 1, 0);
        adj.resize(n);
        
        int len = connections.size();
        for(int i = 0; i<len; i++){
            int a = connections[i][0], b = connections[i][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(1,-1);
        
        return res;
    }
};
