class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> res(n), adj(n);
        for(auto &e : edges) adj[e[1]].push_back(e[0]);
        
        
        
        for(int i = 0; i<n; i++){
            queue<int> q;
            vector<int> vis(n,0);
            vis[i] = 1;
            q.push(i);
            
            while(q.size() > 0){
                int v = q.front(); 
                q.pop();
                for(auto &u : adj[v]){
                    if(!vis[u]){
                        vis[u] = 1;
                        res[i].push_back(u);
                        q.push(u);
                    }
                }
            }
            sort(begin(res[i]), end(res[i]));
        }

        return res;
    }
};
