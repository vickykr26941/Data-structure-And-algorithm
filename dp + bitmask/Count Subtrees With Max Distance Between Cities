/*
  auther : vicky kumar
  date : 07/07/2021
  problem : https://leetcode.com/problems/count-subtrees-with-max-distance-between-cities/
  
*/


class Solution {
public:
    
    const int inf = 1e9 + 7;
    vector<vector<int>> dist;
    int max_dist(int v,int n){
       int edges = 0, node = 0;
       int val = 0;
       for(int i=0; i<n; i++){
           if((v&(1<<i))==0) continue;
           node++;
           for(int j=i+1; j<n; j++){
               if((v&(1<<j))==0) continue;
               if(dist[i][j] == 1) edges++;
               val = max(val, dist[i][j]);
           }
       }
        
       if(node-1==edges) return val;
       return 0;
    }
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        int len = edges.size();
        
        dist = vector<vector<int>>(n,vector<int>(n ,inf));
        for(int i=0; i<n; i++) dist[i][i] = 0;
        for(int i=0; i<len; i++){
            int from = edges[i][0] - 1, to = edges[i][1] - 1;
            dist[from][to] = 1;
            dist[to][from] = 1;
        }
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
                }
            }
        }
        
        vector<int> res(n-1,0);
        for(int i = 0; i<(1<<n); i++){
            int d = max_dist(i,n);
            if(d > 0)
                res[d - 1] ++;
        }
        
        return res;
    }
};
