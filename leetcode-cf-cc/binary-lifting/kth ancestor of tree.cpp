/*
  auther : vicky kumar
  date : 31/08/2021
  source : https://leetcode.com/problems/kth-ancestor-of-a-tree-node/
*/


class TreeAncestor {
public:
    int LOG = 22;
    vector<vector<int>> up;
    vector<int> depth;
    TreeAncestor(int n, vector<int>& parent) {
        // while((1 << LOG) < n) LOG++;
        up = vector<vector<int>>(n,vector<int>(LOG,-1));
        depth = vector<int>(n);
        
        for(int v = 0; v < n; v ++)
            up[v][0] = parent[v];
        for(int v = 0; v < n; v++){
            // up[v][0] = parent[v];
            for(int j = 1; j<LOG; j++){
                if(up[v][j-1] != -1){
                    up[v][j] = up[up[v][j-1]][j-1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int j = 0; j < LOG; j++){
            if(k & (1 << j)){
                node = up[node][j];
                if(node == -1) return node;
            }
        }
    return node;
    }
};
