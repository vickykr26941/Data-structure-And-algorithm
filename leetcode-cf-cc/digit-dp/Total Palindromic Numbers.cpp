    // https://www.codechef.com/problems/AOPN


#include<bits/stdc++.h>
#define int long long int
using namespace std;
string s;
int a,b;
int dp[20][2][2][2][2][11][11];
int solve(int pos,int ta,int st,int odd,int even,int lst,int slst){
	if(pos == s.size())
		return (odd and even);
	else if(dp[pos][ta][st][odd][even][lst][slst] != -1)
		return dp[pos][ta][st][odd][even][lst][slst];
	int ans = 0;
	if(st==0){
		ans += solve(pos+1,ta&(s[pos]=='0'),0,odd,even,lst,slst);
		int en = ta?(s[pos]-'0') : 9;
		for(int i=1; i<=en; i++){
			ans += solve(pos+1,ta&(i==en),1,odd,even,i,slst);
		}
	}
	else{
		int en = ta?(s[pos]-'0'):9;
		for(int i=0; i<=en; i++){
			ans += solve(pos+1,ta&(i==en),1,odd|(i==slst),even|(i==lst),i,lst);
		}
	}
	return dp[pos][ta][st][odd][even][lst][slst] = ans;
}
void test_case(){
	cin>>a>>b;

	memset(dp,-1,sizeof dp);
	s = to_string(b);
	int ans = solve(0,1,0,0,0,10,10);

	memset(dp,-1,sizeof dp);
	s = to_string(a);
	ans -= solve(0,1,0,0,0,10,10);
	cout<<ans;
}
signed main(){
	int t= 1; cin>>t;
	while(t--){
		test_case();
		cout<<endl;
	}
	return 0;
}
