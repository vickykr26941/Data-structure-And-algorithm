#include<bits/stdc++.h>
using namespace std;
void test_case(){
	int n,m; cin>>n>>m;
	string s,r; cin>>s>>r;

	int d = 256, p = 0, t = 0, h = 1;
	int i, j, q = 101; // prime number 

	 // h = pow(d, m - 1)
	for(i=0; i<m-1; i++)
	  h = (h * d) % q;

	for(i=0; i<m; i++){
		t = (d * t + s[i]) % q;
		p = (d * p + r[i]) % q;
	}

	vector<int> occ;
	for(i=0; i<=n-m; i++){
		if(t == p){
			// check
			j = 0;
			for(j=0; j<m; j++){
				if(r[j] != s[i+j])
					break;
			}
			if(j == m){
				occ.push_back(i);
			}
		}
		if(i < n - m){
			t = (d * (t - s[i] * h) + s[i + m]) % q;
			if(t < 0){
				t = t + q;
			}
		}
	}

	for(int i=0; i<occ.size(); i++){
		cout<<occ[i]<<" ";
	}
}
int main(){
	int t = 1; cin>>t;
	while(t --){
		test_case();
		cout<<"\n";
	}

	return 0;
}
