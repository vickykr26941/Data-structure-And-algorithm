/*
 vicky kumar
 date : 15/08/2021
*/

// KMP string matching algorithm


#include<bits/stdc++.h>
using namespace std;
void test_case(){
	string text,pattern;
	cin>>text>>pattern;

	int n = text.size(), m = pattern.size();
	vector<int> lps(m,0);   // longest prefix and suffix match
	for(int i=1, j = 0; i<m; i++){
		while(j > 0 && pattern[i] != pattern[j]){
			j = lps[j - 1];
		}
		if(pattern[i] == pattern[j])
			lps[i] = ++j;
	}

	vector<int> occ;
	for(int i=0,j=0
		; i<n; i++){
		while(j > 0 && text[i] != pattern[j]){
			j = lps[j - 1];
		}
		if(pattern[j] == text[i])
			j++;
		if(j == m){
			occ.push_back(i-m + 1);
		}
	}
	for(int i=0; i<occ.size(); i++){
		cout<<occ[i]<<" ";
	}
}
int main(){
	int t = 1; cin>>t;
	while(t--){
		test_case();
		cout<<'\n';
	}
  
	return 0;
}
