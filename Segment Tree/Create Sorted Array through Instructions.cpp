 // using BIT
// https://leetcode.com/problems/create-sorted-array-through-instructions/

class Solution {
public:
    
    const int mod = 1e9 + 7;
    int max_n = 1e5 + 5;
    int v[100005];
    
    void add(int pos, int val){
        while(pos < max_n){
            v[pos] += val;
            pos += pos & -pos;
        }
    }
    int query(int pos){
        
        int s = 0;
        while(pos > 0){
            s += v[pos];
            pos -= pos & -pos;
        }
        return s;
    }
    int createSortedArray(vector<int>& arr) {
        memset(v, 0, sizeof(v));
        
        int ans = 0;
        for(int i = 0; i < arr.size(); i ++){
            int left = query(arr[i] - 1);
            int right = query(max_n - 2) - query(arr[i]);
            
            ans += min(left, right);
            ans %= mod;
            add(arr[i], 1);
        }
        
        return ans;
    }
};


// using segment tree
// 1 based indexed segment tree



const int mod = 1e9 + 7;
class SumSegmentTree {
 public:
  int n;
  vector<int> tree;
  SumSegmentTree(int n_) : n(n_) {
    int size = (int)(ceil(log2(n)));
    size = (2 * pow(2, size)) - 1;
    tree = vector<int>(size, 0);
  }
  
  int total_sum() { return tree[0]; }

  int query(int l, int r) { return query_util(0, l, r, 0, n - 1); }

  int query_util(int i, int qL, int qR, int l, int r) {
    if (l >= qL && r <= qR) return tree[i];
    if (l > qR || r < qL) return 0;

    int m = (l + r) / 2;
    return query_util(2 * i + 1, qL, qR, l, m) + query_util(2 * i + 2, qL, qR, m + 1, r);
  }

  void update(int i, int val) { update_util(0, 0, n - 1, i, val); }
  void update_util(int i, int l, int r, int pos, int val) {
    if (pos < l || pos > r) return;
    if (l == r) {
      tree[i] += val;
      return;
    }
    int m = (l + r) / 2;
    update_util(2 * i + 1, l, m, pos, val);
    update_util(2 * i + 2, m + 1, r, pos, val);
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
  }
};
class Solution {
public:
    int createSortedArray(vector<int>& arr) {
        
        int n = 1e5 + 1;
        SumSegmentTree t(n);
        
        int ans = 0;
        for(int i = 0; i < arr.size(); i ++){
            int left = t.query(0, arr[i] - 1);
            int right = t.query(arr[i] + 1, n - 1);
            
            ans += min(left, right);
            ans %= mod;
            t.update(arr[i], 1);
        }
        
        return ans;
    }
};
