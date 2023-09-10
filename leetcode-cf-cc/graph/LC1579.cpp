// https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/
// date : 7/9/22

class UnionFind{
    vector<int> id;
    int size;
public:
    UnionFind(int N ): id(N), size(N) {
        iota(begin(id), end(id), 0);
    }
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
    int connected(int a, int b) {
        return find(a) == find(b);
    }
    void connect(int a, int b) {
        int p = find(a), q = find(b);
        if (p == q) return;
        id[p] = q;
        --size;
    }
    int getSize() { return size; }
};
class Solution {
public:
    

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(begin(edges) , end(edges), [&](vector<int> &x, vector<int> &y){ return x[0] > y[0]; });
        
        UnionFind a(n), b(n);
        
        // first connect for type 3
        
        int ans = 0;
        for(int i = 0; i < edges.size(); i ++){
            int type = edges[i][0], x = edges[i][1], y = edges[i][2];
            x --, y --;
            if(type != 3) continue;
            if(!a.connected(x, y) | !b.connected(x, y)){
                ans ++;
            }
            a.connect(x, y);
            b.connect(x, y);
        }
        
        for(int i = 0; i < edges.size(); i ++){
            int type = edges[i][0], x = edges[i][1], y = edges[i][2];
            x --, y --;
            if(type == 3) continue;
            if(type == 1){
                if(!a.connected(x, y)){
                    a.connect(x, y);
                    ans ++;
                }
            }else{
                if(!b.connected(x, y)){
                    b.connect(x, y);
                    ans ++;
                }
            }
        }
        
        return (a.getSize() == 1 && b.getSize() == 1) ? (int)edges.size() - ans : -1;
        
    }
};
