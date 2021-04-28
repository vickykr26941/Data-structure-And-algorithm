#include<iostream>
#include<vector>
using namespace std;
const int inf=10e8;
vector<int> st;
void build_tree(vector<int> &arr,int v,int lt,int rt){
 	if(lt==rt){
 		st[v]=arr[lt];
	  }else{
	  	 int k=(lt+rt)/2;
	  
	     build_tree(arr,v*2,lt,k);
	     build_tree(arr,v*2+1,k+1,rt);
	  
	     st[v]=st[v*2] + st[v*2+1];
	  }
}
int quary(int v,int lt,int rt,int l,int r){
	if(lt>r || rt <l) return 0;
	else if(lt>=l && rt<=r) return st[v];
	
	int k=(lt+rt)/2;
	return quary(v*2,lt,k,l,r) + quary(v*2+1,k+1,rt,l,r);
}

void point_update(int v,int lt,int rt,int qt,int val){
	if(lt==rt){
		st[v]+=val;
		return;
	}
   int k=(lt+rt)/2;
   if(qt<=k) point_update(v*2,lt,k,qt,val);
   else    point_update(v*2 +1,k+1,rt,qt,val);
   st[v]=st[v*2] + st[v*2+1];
}
int main(){
	int n;
	cin>>n;
	vector<int> arr(n,0);
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	st.assign(n*4,0);
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
		}else{
			int a,b;
			cin>>a>>b;
			point_update(1,1,n,a,b);
		}
	}
	return 0;
}
