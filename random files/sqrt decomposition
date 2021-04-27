// sqrt root decomposition (reange sum query ... reference : cp algorithms)
#include<bits/stdc++.h> 
#define int long long
#define vi vector<int>
#define vii vector<vi>
#define pii pair<int,int>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define rrep(i,a,b) for(int i=a; i>=b; i--)
#define pb(i) push_back(i)
#define all(b) b.begin(),b.end()
using namespace std;
const int mod = 1e9 + 7;
const int inf = 1e10 + 20;
const int mxn = 1e5 + 10;
int b[mxn];
int a[mxn];
int n; 
int query(int l,int r){
	int len = (int) sqrt(n + .0)  + 1;
	int s = 0;
	int c_l = l/len, c_r = r / len; // left block / right bolck 
	if(c_l == c_r){
		rep(i,l, r + 1){
			s += a[i];
		}
		return s;
	}
	else{
		int end = (c_l + 1) * len;
		rep(i, 0, end){
			s += a[i];
		}
		rep(i,c_l + 1, c_r){
			s += b[i];
		}
		rep(i,c_r * len, r + 1){
			s += a[i];
		}
		return s;
	}
}
void test_case(){
    cin>>n;
	rep(i,0,n){
		cin>>a[i];
	}
	rep(i,0,mxn){
		b[i] = 0;
	}
	int s= 0;
	int len = (int) sqrt(n + .0) + 1;
	rep(i,0,n){
		b[i/len] += a[i];
	}

	   // query 
	int q; cin>>q;
	while(q--){
		int l,r; cin>>l>>r;
		cout<<query(l,r)<<"\n";
	}
}
 signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;  cin>>t;
    while(t--){
        test_case();
        cout<<'\n';
    }
    return 0;
}
