// https://cses.fi/problemset/task/1649/

 // 1 based indexing 
 
 
// #include<bits/stdc++.h>
// #define int long long int
// using namespace std;


// #define ar array

// const int MAX_N = 2e5 + 1;
// const int MOD = 1e9 + 7;
// const int INF = 1e18;

// int n, q, arr[MAX_N], st[MAX_N * 4];
// void build(int node, int start, int end) {
// 	if (start == end) {
// 		st[node] = arr[start];
// 		return;
// 	}
// 	int mid = (start + end) / 2;
// 	build(2 * node, start, mid);
// 	build(2 * node + 1, mid + 1, end);
// 	st[node] = min(st[2 * node], st[2 * node + 1]);
// }
// void update(int node, int start, int end, int idx, int val) {
// 	if (start == end) {
// 		arr[idx] = val;
// 		st[node] = val;
// 		return;
// 	}
// 	int mid = (start + end) / 2;
// 	if (idx <= mid) update(2 * node, start, mid, idx, val);
// 	else update(2 * node + 1, mid + 1, end, idx, val);
// 	st[node] = min(st[2 * node], st[2 * node + 1]);
// }
// void update(int idx, int val) {
// 	update(1, 1, n, idx, val);
// }
// int query(int node, int start, int end, int l, int r) {
// 	if (start > r || end < l) return INF;
// 	if (l <= start && r >= end) return st[node];
// 	int mid = (start + end) / 2;
// 	return min(query(2 * node, start, mid, l, r), query(2 * node + 1, mid + 1, end, l, r));
// }
// int query(int l, int r) {
// 	return query(1, 1, n, l, r);
// }
// void test_case() {

// 	// 1 index based
// 	cin >> n >> q;
// 	for (int i = 1; i <= n; i++) cin >> arr[i];
// 	build(1, 1, n);

// 	while (q--) {
// 		int t; cin >> t;
// 		if (t == 1) {
// 			// update
// 			int idx, val; cin >> idx >> val;
// 			update(idx, val);
// 		} else {
// 			int l, r; cin >> l >> r;
// 			cout << query(l, r) << '\n';
// 		}
// 	}
// }
// signed main() {
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0); cout.tie(0);


// 	int t = 1;
// 	// cin >> t;
// 	for (int tc = 1; tc <= t; tc++) {
// 		test_case();
// 		cout << '\n';
// 	}
// 	return 0;
// }




// 0 based indexing segment tree


#include <bits/stdc++.h>
#define int long long int

using namespace std;
const int MAX_N = 2e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e18;

int n, q, arr[MAX_N], st[4 * MAX_N];
void build(int node, int start, int end) {
	if (start == end) {
		st[node] = arr[start];
		return;
	}
	int mid = (start + end) / 2;
	build(2 * node, start, mid);
	build(2 * node + 1, mid + 1, end);

	st[node] = min(st[2 * node], st[2 * node + 1]);
}
void update(int node, int start, int end, int idx, int val) {
	if (start == end) {
		arr[idx] = val;
		st[node] = val;
		return;
	}
	int mid = (start + end) / 2;
	if (idx <= mid) update(2 * node, start, mid, idx, val);
	else update(2 * node + 1, mid + 1, end, idx, val);

	st[node] = min(st[2 * node], st[2 * node + 1]);
}
void update(int idx, int val) {
	update(1, 0, n - 1, idx, val);
}
int query(int node, int start, int end, int l, int r) {
	if (start > r || end < l) return INF;
	if (l <= start && r >= end) return st[node];
	int mid = (start + end) / 2;
	return min(query(2 * node, start, mid, l, r), query(2 * node + 1, mid + 1, end, l, r));
}
int query(int l, int r) {
	return query(1, 0, n - 1, l, r);
}
void test_case() {
	cin >> n >> q;
	for (int i = 0; i < n; i++) cin >> arr[i];

	build(1, 0, n - 1);

	while (q--) {
		int t; cin >> t;

		// update
		if (t == 1) {
			int idx, val; cin >> idx >> val;
			idx --;
			update(idx, val);
		} else {
			int l, r; cin >> l >> r;
			l--, r--;
			cout << query(l, r) << '\n';
		}
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


