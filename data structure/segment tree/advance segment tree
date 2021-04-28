#include<iostream>
#include<conio.h>
#include<vector>
using namespace std;
const int inf=10e8;
using pii=pair<int,int>;
vector<pii> st;
pii combine(pii a,pii b){
	if(a.first>b.first) return a;
	if(b.first> a.first) return b;
	return {a.first,a.second+b.second};
}
void build_tree(vector<int> &arr,int v,int s,int e){
	if(s==e){
		st[v]=make_pair(arr[s],1);
	}else{
		int k=(s+e)/2;
		build_tree(arr,2*v,s,k);
		build_tree(arr,2*v+1,k+1,e);
		
		st[v]=combine(st[v*2],st[v*2+1]);
	}
}
void update(int v,int s,int e,int q,int val){
	if(s==e){
		st[v]={val,1};
	}else{
		int k=(s+e)/2;
		if(q<=k) update(2*v,s,k,q,val);
		else   update(2*v+1,k+1,e,q,val);
		
		st[v]=combine(st[2*v],st[2*v+1]);
	}
} 
pii quary(int v,int s,int e,int l,int r){
	if(s>r || e<l) return {inf,-1};
	if(s>=l && e<=r) return st[v];
	int k=(s+e)/2;
	return combine(quary(2*v,s,k,l,r),quary(2*v+1,k+1,e,l,r));
}
int mian(){
	int n;
	cin>>n;
	vector<int> arr(n,0);
	for(int i=0; i<n; i++)
	 cin>>arr[i];
	st.resize(4*n);
	build_tree(arr,1,0,n-1);
	int q;
	cin>>q;
	while(q--){
		int code;
		cin>>code;
		if(code==0){
			int a,b;
			cin>>a>>b;
			pii p=quary(1,1,n,a,b);
			cout<<p.first<<" "<<p.second<<endl;
		}
		else{
			int a,c;
			cin>>a>>c;
			update(1,1,n,a,c);
		}
	}
	
 return 0;
}






// finding the subsegment with the maximal sum
// we need to store maximum sum ,maximum prefix sum, maximum suffix sum to find the maximum subsegment

#include<iostream>
#include<vector>
using namespace std;
struct data{
	int sum,pre_sum,suf_sum,ans;
};

vector<data> st;
data combine(data l,data r){
	data res;
	res.sum=l.sum+r.sum;
	res.pre_sum=max(l.pre_sum,l.sum+r.pre_sum);
	res.suf_sum=max(r.suf_sum,r.sum+l.suf_sum);
	res.ans=max(max(l.ans,r.ans),l.suf_sum+r.pre_sum);

return res;
}
data make_data(int val){
	data res;
	res.sum=val;
	res.pre_sum=res.suf_sum=res.ans=max(0,val);
	return res;
}
void build_tree(vector<int> &arr,int v,int s,int e){
	if(s==e){
		st[v]=make_data(arr[s]);
	}else{
		int k=(s+e)/2;
		build_tree(arr,2*v,s,k);
		build_tree(arr,2*v+1,k+1,e);
		
		st[v]=combine(st[2*v],st[2*v+1]);
	}
}
void update(int v,int s,int e,int q,int val){
	if(s==e){
		st[v]=make_data(val);
	}else{
		int k=(s+e)/2;
		if(q<=k) update(2*v,s,k,q,val);
		else   update(2*v+1,k+1,e,q,val);
		st[v]=combine(st[2*v],st[2*v+1]);
	}
}
data query(int v,int s,int e,int l,int r){
	if(s>r || e<l) return make_data(0);
	if(s>=l && e<=r) {
		return st[v];
	}
	int k=(s+e)/2;
	return combine(query(2*v,s,k,l,r),query(2*v+1,k+1,e,l,r));
}
int main(){
	int n;
	cin>>n;
	vector<int> arr(n,0);
	for(int i=0; i<n; i++)
	cin>>arr[i];
	
	st.assign(4*n,make_data(0));
	build_tree(arr,1,0,n-1);
	
	int q;
	cin>>q;
	while(q--){
		int code;
		cin>>code;
		if(code==0){
			int a,b;
			cin>>a>>b;
			cout<<query(1,1,n,a,b).ans<<endl;
		}else{
			int a,c;
			cin>>a>>c;
			update(1,1,n,a,c);
		}
	}
	
	return 0;
}
