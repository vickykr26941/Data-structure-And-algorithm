//searching the k'th zeros in array /searching the kth particular number /chracter /string /pair/or any kth searching probleam can be solved 
// by segment tree 
// below the example to searching the k'th zeros in the array/ or finding the first segment that conctain k zero's
//return :the index of the k'th zero 


#include<iostream>
#include<vector>
using namespace std;
vector<int> st;
void build_tree(vector<int> &arr,int v,int s,int e){
	if(s==e){
		st[v]=(arr[s]==0);
	}else{
		int k=(s+e)/2;
    	build_tree(arr,2*v,s,k);
	    build_tree(arr,2*v+1,k+1,e);
		st[v]=st[2*v]+st[2*v+1];
	}
	
}
int sum(int v,int s,int e,int l,int r){  //return the sum of range
	if(s>r || e<l) return 0;
	if(s>=l && e<=r) return st[v];
	int k=(s+e)/2;
	return sum(v*2,s,k,l,r) + sum(v*2+1,k+1,e,l,r);
}
int find_kth(int v,int s,int e,int k){  // query is to find the position of kth 0 in array
	if(k>st[v]) return -1;
	if(s==e) return s;
	int mid=(s+e)/2;
	if(st[2*v]>k) return find_kth(2*v,s,mid,k);
	else        return find_kth(2*v+1,mid+1,e,k-st[v*2]);
}
int main(){
	int n;
	cin>>n;
	vector<int> arr(n,0);
	for(int i=0; i<n; i++)
	cin>>arr[i];
	
	st.assign(4*n,0);
	build_tree(arr,1,0,n-1);
	
	 int q;
	 cin>>q;
	 while(q--){
	 	int c;
	 	cin>>c;
	 	cout<<find_kth(1,1,n,c);   // find the position of kth zero
	 }
	
	return 0;	
}
