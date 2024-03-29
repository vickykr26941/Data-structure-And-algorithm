/*
   auther : vicky kumar 
   date : 25/07/2021
   source : https://www.codechef.com/START6B/problems/HMWPRB
*/

// explanation 
// problem can be solved using dynamic programming 
// dp[i] = minimum possible coins to do till ith assignment 
// dp[i] = a[i] + min(dp[j]) where i - k - 1 <= j < =i
// this can be done using segment tree easily with range minimum query and range upate 
// but if we maintain monotonic increasing deque then we can extract minimum from the front of the deque


#include<bits/stdc++.h>
using namespace std;
void test_case(){
   int n,k; cin>>n>>k;
   vector<int> a(n,0);
   for(int i=0; i<n; i++){
    cin>>a[i];
   }
   deque<pair<int,int>> q;
   vector<int> dp(n,0);
   for(int i=0; i<=k; i++){
    dp[i] = a[i];
    while(q.size() > 0 && q.back().first > dp[i])
        q.pop_back();

     // front element will always be minimum
    q.push_back({dp[i],i}); 
   }
   for(int i=k+1; i<n; i++){
    while(q.size() > 0 && q.front().second < i - k - 1){
        q.pop_front();
    }
    int min_val = 0;
    if(q.size() > 0 )
        min_val = q.front().first;
    dp[i] = a[i] + min_val;
    while(q.size() > 0 && q.back().first > dp[i]){
        q.pop_back();
    }
    q.push_back({dp[i],i});
   }

   int ans = INT_MAX;
   for(int i=n-k-1; i<n; i++){
    ans = min(ans,dp[i]);
   }
   cout<<ans;
}
int main(){
    int t = 1; cin>>t;
    while(t --){
        test_case();
        cout<<'\n';
    }

    return 0;
}
