/*
  vicky kumar
  date : 07/10/2021
  problem : https://leetcode.com/problems/couples-holding-hands/
  
*/


class Solution {
public:
    
    vector<vector<int>> g;
    vector<int> vis;
    
    void take_size(int from,int &cluster_size){
        vis[from] = 1;
        cluster_size ++;
        for(auto &to : g[from]){
            if(!vis[to]){
                take_size(to,cluster_size);
            }
        }
    }
    int get_id(int x){
        return x / 2;
    }
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        for(auto &x : row) x = get_id(x);
        
        
        g = vector<vector<int>>(n);
        vis.assign(n, 0);
        
        for(int i = 0; i<n; i+=2){
            int c1 = row[i], c2 = row[i + 1];
            if(c1 == c2) continue;
            g[c1].push_back(c2);
            g[c2].push_back(c1);
        }
        
        int ans = 0;
        
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                int cluster_size = 0;
                take_size(i,cluster_size);
                ans += cluster_size - 1;
            }
        }
        
        return ans;
    }
};
