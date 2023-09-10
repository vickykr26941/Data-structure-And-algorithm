

// https://leetcode.com/problems/process-restricted-friend-requests/



class RangeFreqQuery {
public:
    vector<int> &A;
    vector<vector<int>> T;
    
    int N;
    void build(int v,int tl,int tr){
        if(tl == tr){
            T[v] = {A[tl]};
        }else{
            int mid = (tl + tr) / 2;
            build(2 * v, tl,mid);
            build(2 * v + 1, mid + 1,tr);
            T[v].resize(tr - tl + 1);
            auto &L = T[2 * v], &R = T[2 * v + 1];
            merge(begin(L),end(L),begin(R),end(R),begin(T[v]));
        }
    }
    RangeFreqQuery(vector<int>& arr) : A(arr){
        N = arr.size();
        T.resize(4 * N);
        build(1,0,N - 1);
    }
    int query(int v,int L,int R,int l,int r,int x){
        if(l > R || r < L) return 0;
        if(L >= l && R <= r){
            int right = upper_bound(begin(T[v]),end(T[v]),x) - begin(T[v]);
            int left = lower_bound(begin(T[v]),end(T[v]),x) - begin(T[v]);
            return right - left;
        }
        int mid = (L + R) / 2;
        int ql = query(2 * v,L,mid,l,r,x);
        int qr = query(2 * v + 1, mid + 1,R,l,r,x);
        return ql + qr;
    }
    int query(int left, int right, int value) {
        return query(1,0,N - 1,left,right,value);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */



// leetcode :


#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAX_N = 2e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e18;

int n, q;
vector<int> A;  // value array
vector<vector<int>> T; // to store tree information

void build(int v, int tl, int tr) {
	if (tl == tr) T[v] = {A[tl]};
	else {
		int mid = (tl + tr) / 2;
		build(2 * v, tl, mid);
		build(2 * v + 1, mid + 1, tr);
		T[v].resize(tr - tl + 1);
		auto &L = T[v * 2], &R = T[2 * v + 1];
		merge(begin(L), end(L), begin(R), end(R), begin(T[v]));
	}
}
int query(int x, int l, int r, int v, int L, int R) {
	if (l > R || r < L) return 0;
	if (l <= L && r >= R) {
		int right = upper_bound(begin(T[v]), end(T[v]), x) - begin(T[v]);
		int left = lower_bound(begin(T[v]), end(T[v]), x) - begin(T[v]);
		return right - left;
	}
	int mid = (L + R) / 2;
	int ql = query(x, l, r, 2 * v, L, mid);
	int qr = query(x, l, r, 2 * v + 1, mid + 1, R);
	return ql + qr;
}
int query(int l, int r, int x) {
	return query(x, l, r, 1, 0, n - 1);
}
void test_case() {
	cin >> n >> q;
	vector<int> arr(n, 0);
	for (int i = 0; i < n; i++) cin >> arr[i];
	A = arr;

	T.resize(4 * n);
	build(1, 0, n - 1);

	while (q --) {
		int l, r, val; cin >> l >> r >> val;
		cout << query(l, r, val) << '\n';
	}
}
signed main() {
	int t = 1; // cin >> t;
	for (int i = 1; i <= t; i++) {
		test_case();
		cout << '\n';
	}


	return 0;
}
