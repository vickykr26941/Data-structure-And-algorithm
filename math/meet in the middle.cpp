       // https://www.geeksforgeeks.org/meet-in-the-middle/

#include<bits/stdc++.h> 
#define int long long
#define vi vector<int>
#define vii vector<vi>
#define pii pair<int,int>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define rrep(i,a,b) for(int i=a; i>=b; i--)
#define pb(i) push_back(i)
#define all(b) b.begin(),b.end()

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;
// template<class T> using oset =tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update> ;
// st.find_by_order(k); // returns element at position k(0 based indexing)
// st.find_of_key(k); // number of element <k
// st.order_of_key(k); // return order of k 
// less_equal<T> : as multiset
// less<T>      :  only set

const int mod = 1e9 + 7;
const int inf = 1e10 + 20;
const int mxn = 1e7 + 1;
void solve(vector<int>&a,int n,vector<int>&v,int val){
    if(n==0){
        v.push_back(val);
        return;
    }
    solve(a,n-1,v,val+a[n-1]);
    solve(a,n-1,v,val);
}
void test_case(){
    int n,target; cin>>n>>target;
    vector<int> a(n,0);
    for(int i=0; i<n; i++)
        cin>>a[i];
    int l = n/2, r = n - n/2;
    int len = 1<<l;


       // recursive approach 
    // vector<int> L;
    // solve(a,n/2,L);
    // vector<int> R;
    // vector<int> b(n-n/2,0);
    // for(int i=l; i<n; i++)
    //     b.push_back(a[i]);

    // solve(b,b.size(),R);



    // iterative approach 
    vector<int> L(len,0);
    for(int i=0; i<len; i++){
        int s = 0;
        for(int j=0; j<l; j++){
            if(i & (1<<j)){
                s += a[j];
            }
        }
      L[i] = s;
    }

    len = 1<<r;
    vector<int> R(len,0);
    for(int i=0; i<len; i++){
        int s = 0;
        for(int j=0; j<r; j++){
            if(i & (1<<j)){
                s += a[l + j];
            }
        }
     R[i] = s;
    }

    sort(all(R));
    int mx = 0;
    for(int i=0; i<l; i++){
        if(L[i] > target) continue;
        int pos = lower_bound(all(R),target-L[i]) - begin(R);
        if(pos==n or target != (R[pos] + L[i]))
            pos--;
        if((R[pos] + L[i]) > mx){
            mx = R[pos] + L[i];
        }
    }
    cout<<mx;
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
