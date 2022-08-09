   // query min index,max index,min,max,sum and many more 
      
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
const int mxn = 1e5 + 10;
int N, P;
vii dp1,it1; // for min 
vii dp2,it2; // for max
vi log_2;
void init_table(vi &a){
     // make sure to clear for each test case
    for(int i=0; i<dp1.size(); i++)
        dp1[i].clear();
    dp1.clear();

    for(int i=0; i<dp2.size(); i++)
        dp2[i].clear();
    dp2.clear();
    it1.clear();
    it2.clear();
    log_2.clear();


    N = a.size();
    P = log2(N) + 1;
    dp1.assign(P+1,vi(N,0));
    it1.assign(P+1,vi(N,0));
    log_2.assign(N+1,0);
    dp2.assign(P+1,vi(N,0));
    it2.assign(P+1,vi(N,0));


    for(int i = 2; i <= N; i++)
        log_2[i] = log_2[i/2] + 1;

    for(int i = 0; i <  N; i++){
        dp1[0][i] = a[i];
        it1[0][i] = i;
        dp2[0][i] = a[i];
        it2[0][i] = i;
    }
    int x1,y1,x2,y2;
    for(int p = 1; p <= P; p++){
        for(int i = 0; i + (1 << p) <= N; i++){
            // mn_val 
            x1 = dp1[p-1][i];
            y1 = dp1[p-1][i + (1 << (p - 1))];
            dp1[p][i] = min(x1,y1); 

            // mx_val
            x2 = dp2[p-1][i];
            y2 = dp2[p-1][i + (1 << (p - 1))];
            dp2[p][i] = max(x2,y2);

            // min_index 
            if(x1 <= y1)
                it1[p][i] = it1[p - 1][i];
            else
                it1[p][i] = it1[p - 1][i + (1 << (p - 1))];

            // max_index
            if(x2 >= y2)
                it2[p][i] = it2[p-1][i];
            else
                it2[p][i] = it2[p - 1][i + (1 << (p - 1))];

        }
    }
}
// smallest element in range  O(1)
int min_query(int l,int r){
    int len = r - l + 1;
    int p = log_2[len];
    int left = dp1[p][l];
    int right = dp1[p][r - (1 << p) + 1];
    return  min(left, right);
}
int max_query(int l,int r){
    int len = r - l + 1;
    int p = log_2[len];
    int left = dp2[p][l];
    int right = dp2[p][r - (1 << p) + 1];

    return max(left, right);
}
// smallest element in range O(logn)
// int min_query(int l,int r){
//     int min_val = inf;
//     for(int p = log2[r - l + 1]; l <= r; p = log2[r - l + 1]){
//         min_val = min(min_val,dp1[p][l]);
//         l += (1 << p);
//     }
//     return min_val;
// }

int min_index(int l,int r){
    int len = r - l + 1;
    int p = log_2[len];
    int left = dp1[p][l];
    int right = dp1[p][r - (1 << p) + 1];

    if(left <= right)
        return it1[p][l];
    return it1[p][r - (1 << p) + 1];
}
int max_index(int l,int r){
    int len = r - l + 1;
    int p = log_2[len];
    int left = dp2[p][l];
    int right = dp2[p][r - (1 << p) + 1];

    if(left>=right)
        return it2[p][l];
    return it2[p][r - (1 << p) + 1];
}
void test_case(){
    // take the values init the table 
    // 0 based indexing do left--,right-- 
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
