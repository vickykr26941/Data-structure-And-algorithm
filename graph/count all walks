// Count all possible walks from a source to a destination with exactly k edges// 
// https://www.geeksforgeeks.org/count-possible-paths-source-destination-exactly-k-edges/
// // solutin :  use dp to solve
 dp[i][j][k] -> total count of edges from i to j with exectely k distance 
 transition 
     for each eadges from i to a : 
       dp[i][j][k] += dp[a][j][k-1];
 
 ans = dp[source][destination][len]


 // recursion  + memoization 
 // time : n ^ 3 
#include<bits/stdc++.h>
#define int long long int
using namespace std;
vector<vector<int>> g;
vector<vector<vector<int>>> dp;
int solve(int u,int v,int k){
	if(k==0 && u==v) return 1;
	if(k==1 && g[u][v]>0) return 1;
	if(k <=0 ) return 0;
	else if(dp[u][v][k] != -1)
		return dp[u][v][k];

	int ans = 0;
	for(int i=0; i<g.size(); i++){
		if(g[u][i] == 1)
			ans += solve(i,v,k-1);
	}
	return dp[u][v][k] = ans;
}
signed main(){
	int t; cin>>t;
	while(t--){
		int n,u,v,k; cin>>n>>u>>v>>k;
		g.clear();
		g = vector<vector<int>>(n,vector<int>(n,0));
		dp = vector<vector<vector<int>>>(n,vector<vector<int>>(n,vector<int>(k + 1,-1)));

		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin>>g[i][j];
			}
		}
		int ans = solve(u,v,k);
		cout<<ans;
	}

	return 0;
}



// top down dp
#include<bits/stdc++.h>
#define int long long int
using namespace std;
vector<vector<int>> g;
vector<vector<vector<int>>> dp;
signed main(){
	int t = 1; cin>>t;
	while(t--){
		int n,u,v,k; cin>>n>>u>>v>>k;

		g.clear();
		g = vector<vector<int>>(n,vector<int>(n,0));
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin>>g[i][j];
			}
		}

		dp.clear();
		dp = vector<vector<vector<int>>>(n,vector<vector<int>>(n,vector<int>(k+1,0)));
		for(int e = 0; e<=k; e++){
			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++){

					if(e == 0 && i==j) dp[i][j][e] = 1;
					else if(e==1 && g[i][j] == 1) dp[i][j][e] = 1;
					else{
						for(int a = 0; a < n; a++){
							if(g[i][a] == 1){
								dp[i][j][e] += dp[a][j][k-1];
							}
						}
					}
				}
			}
		}

		int ans = dp[u][v][k];
		ans == 0? cout<<"no way" : cout<<ans;
	}


	return 0;
}


//  // 4 0 3 2
//  // 0 1 1 1 
//  // 0 0 0 1 
//  // 0 0 0 1
//  // 0 0 0 0 
