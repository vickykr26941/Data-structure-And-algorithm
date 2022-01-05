

// date : 6 jan 22
// https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/


class Solution {
public:
    const int MAX_N = 2e5 + 1;
    const int MOD = 1e9 + 7;
    
    int st[4 * 100005];
    int N;
    int build(vector<int> &v,int node,int start,int end){
        if(start == end){
            return st[node] = start;
        }else{
            int mid = (start + end) / 2;
            int left = build(v,2 * node,start,mid);
            int right = build(v,2 * node + 1, mid + 1, end);
            
            return st[node] = v[left] < v[right] ? left : right;
            
        }
    }
    int query(vector<int> &v,int node,int start,int end,int l,int r){
        if(start > r || end < l) return -1;
        if(l <= start && r >= end) return st[node];
        
        int mid = (start + end) / 2;
        int left = query(v,2 * node, start,mid,l,r);
        int right = query(v,2 * node + 1, mid + 1,end,l,r);
        
        if(left == -1) return right;
        else if(right == -1) return left;
        
        return v[left] < v[right] ? left : right;
    }
    int query(vector<int> &v,int l, int r) {
	    return query(v,1, 0, N - 1, l, r);
    }
    int solve(vector<int> &v,int i,int j,int val){
        if(i > j) return 0;
        if(i == j) return v[i] - val;
        int min_index = query(v,i,j);
       // cout << min_index << endl;
        return (v[min_index] - val) + solve(v,i,min_index - 1,v[min_index]) + solve(v,min_index + 1, j,v[min_index]);
    }
    int minNumberOperations(vector<int>& target) {
        
        memset(st,0,sizeof(st));
        build(target,1,0,target.size() -1);
        N = target.size();
        
        return solve(target,0,target.size() - 1,0);
    }
};

