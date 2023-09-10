 // lazy propogation range update 
#include<iostream>
#include<conio.h>
#include<vector>
using namespace std;
const int inf=10e8;
vector<int>st,lazy;
void build_tree(vector<int>&arr,int v,int s,int e){
	if(s==e){
		st[v]=arr[s];
	}else{
		int k=(s+e)/2;
		build_tree(arr,v*2,s,k);
		build_tree(arr,v*2+1,k+1,e);
		
		st[v]=st[v*2]+st[v*2+1];
	}
}
void update_range(int v,int s,int e,int l,int r,int val){
	if(lazy[v]!=0){
		int x=lazy[v];
		st[v]+=x;
		lazy[v]=0;
		
		if(s!=e)
			lazy[2*v]+=x,lazy[2*v+1]+=x;
	}
	if(s>r || e<l) return;
	if(s>=l && e<=r) {
		int x=(e - s + 1)*val;
		st[v]+=x;
		if(s!=e){
			lazy[2*v]+=x,lazy[2*v+1]+=x;
		}
	 return ;
	} 
	
	int k=(s+e)/2;
	update_range(2*v,s,k,l,r,val);
	update_range(2*v+1,k+1,e,l,r,val);
	
	st[v]=st[2*v]+st[2*v+1];
}
int quary(int v,int s,int e,int l,int r){
	if(lazy[v]!=0){
		int x= lazy[v];
		st[v]+=x;
		lazy[v]=0;
		if(s!=e){
			lazy[2*v]+=x,lazy[2*v+1]+=x;
		}
	}
	if(s>r || e<l) return 0;
	if(s>=l && e<=r) return st[v];
	int k=(s+e)/2;
	return quary(2*v,s,k,l,r) + quary(2*v+1,k+1,e,l,r);
	
}
int main(){
	int n;
	cin>>n;
	st.assign(4*n,0);
	lazy.assign(4*n,0);
	vector<int> arr(n,0);
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	build_tree(arr,1,0,n-1);
	int q;
	cin>>q;
	while(q--){
		int code;
		cin>>code;
		if(code==0){
			int a,b;
			cin>>a>>b;
			cout<<quary(1,1,n,a,b)<<endl;
		}
		else{
			int a,b,val;
			cin>>a>>b>>val;
			update_range(1,1,n,a,b,val);
		}
	}
	
 return 0;
}
