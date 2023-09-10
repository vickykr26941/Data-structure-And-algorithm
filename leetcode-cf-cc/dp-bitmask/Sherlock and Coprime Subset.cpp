
      // https://www.hackerearth.com/practice/algorithms/dynamic-programming/bit-masking/practice-problems/algorithm/sherlock-and-coprime-subset/
      // solution : dp + bitmask
 

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

// brute force recursive solution (tle)
// int solve(vector<int>&v,int i,string t){
//     if(i>=v.size())
//         return 0;
//     int ans = solve(v,i+1,t);
//     if(t.size()==0)
//         ans = max(ans, 1 + solve(v,i+1,t+to_string(i)));
//     else{
//         bool ok = true;
//         for(int j=0; j<t.size(); j++){
//             if(__gcd(v[i],v[t[j] - '0']) != 1)
//                 ok = false;
//         }
//         if(ok){
//             ans = max(ans, 1 + solve(v,i+1,t + to_string(i)));
//         }
//     }

//     return ans;
// }

  
  
  
   // optimized
int p[15] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
int dp[101][(1<<15)+ 10];
int a[101], n;

int final_mask = 0;
int solve(int i,int mask){
    if(i==n) return 0;
    int &ret = dp[i][mask];
    if(ret != -1)
        return ret;
    if(a[i]==1) return ret = 1 + solve(i+1,mask);
    ret = solve(i+1,mask);
    for(int j=0; j<15; j++){
        if((a[i] % p[j])==0){
            if(mask & (1<<j))
                return ret;
            mask |= (1<<j);
        }
    }
    ret = max(ret,1+solve(i+1,mask));
    return ret;
}
void test_case(){
    cin>>n;

    final_mask = (1<<n) - 1;
    for(int i=0; i<n; i++)
      cin>>a[i];
    memset(dp,-1,sizeof dp);
    cout<<solve(0,0);
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
