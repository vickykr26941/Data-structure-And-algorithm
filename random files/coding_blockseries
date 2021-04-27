// coding blocks cpp course
// lecture 9
// given some points print the k nearest points from origin with their id

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class points{
public:
	int x,y,id;
	points(int x,int y,int id){
		this->x=x,this->y=y,this->id=id;
	}
	int dist(){
		return x*x+ y*y;
	}
	void print(){
		cout<<this->id<<" location:"<<x<<","<<y<<endl;
	}
};
class comp{
public:
    bool operator()(points a,points b){ 
    	  return a.dist()>b.dist();
    }
};
int main(){
	int n;
	cin>>n;
	//vector<vector<int>> arr(n,vector<int>(2,0));
    priority_queue<points,vector<points>,comp> pq;

	for(int i=0; i<n; i++){
        int x,y;
        cin>>x>>y;
        points p(x,y,i);
        pq.push(p);
	}
	while(!pq.empty()){
         points p=pq.top();
         p.print();
         pq.pop();
	}
    return 0;   
}

// N-quean problem  // it takes O(n) for each cell
// overall time : O(n^n) exponential
#include<iostream>
#include<vector>
#define next_line cout<<endl;
using namespace std;
bool is_valid(vector<vector<int>> &mat,int x,int y){
     for(int i=0; i<=y; i++)
     	if(mat[x][i]) 
     		return false;
     for(int i=0; i<=x; i++)
     	if(mat[i][y]) 
     		return false;
     for(int i=x,j=y; i>=0 && j>=0; i--,j--)
     	if(mat[i][j]) 
     		return false;
     for(int i=x,j=y; i>=0 && j<mat[0].size(); i--,j++)
     	if(mat[i][j]) 
     		return false;
    return true;
} 
bool solve(vector<vector<int>>&mat,int n,int m,int x=0){
	if(x>=n) return true;
	for(int i=0; i<m; i++){  // columns
		if(is_valid(mat,x,i)){
			mat[x][i]=1;
			if(solve(mat,n,m,x+1))
				return true;
			else
				mat[x][i]=0;
		}
	}
	return false;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector<vector<int>> mat(n,vector<int>(m,0));
		bool flag=solve(mat,n,m,0);
		if(flag==false){
			cout<<"queen configuration not possible"<<endl;
		}else{
			for(int i=0; i<n; i++){
				for(int j=0; j<m; j++)
					cout<<mat[i][j]<<" ";
				next_line;
			}
		}
	}
	return 0;
}


// // find the total configuration on N queen probleam 
// // using bitset
#include<iostream>
#include<vector>
#include<bitset>
using namespace std;
bitset<30> col,d1,d2;
void solve(int n,int r,int &ans){
	if(r==n){ans++;return ;}
	for(int c=0; c<n; c++){
		if(!col[c] && !d1[r-c+n-1] && !d2[r+c]){
			col[c]=d1[r-c+n-1]=d2[r+c]=1;
			solve(n,r+1,ans);
			col[c]=d1[r-c+n-1]=d2[r+c]=0;
		}
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int ans=0;
		solve(n,0,ans);
		cout<<ans<<endl;
	}
	return 0;
}

// more optimization on N-queen problem
// using bitmasking + backtracking
  //  find the total number of configuration of N-queen problem
#include<iostream>
#include<vector>
using namespace std;
int done;
void solve(int n,int &ans,int row_mask=0,int ld=0,int rd=0){
     int safe=done&(~(row_mask|ld|rd));
     if(row_mask==done){
     	ans++; return ;
     }
     while(safe){
     	int p=safe &(-safe);
     	safe=safe-p;
        solve(n,ans,row_mask|p ,(ld|p)<<1,(rd|p)>>1);
     }
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,ans=0;
		cin>>n;
		done=(1<<n)-1;
		solve(n,ans);
		cout<<ans<<endl;
	}
	return 0;
}

// print all possible configuration of N- queen problem
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> mat;
int done,n;
int get_col(int n){
	int ans=0;
	while(n>0){
		ans++;
		n=n>>1;
	}
	return ans-1;
}
void solve(int row_mask=0,int ld=0,int rd=0,int row=0){
	if(done==row_mask){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; i++){
				cout<<mat[i][j]<<" ";
			}
			cout<<endl;
		}
		return ;
	}

	int safe=done & (~(ld|rd|row_mask));
	while(safe){
		int p=safe &(-safe);
		safe=safe-p;
		int col=get_col(p);
		mat[row][col]=1;
		solve(row_mask|p,(ld|p)<<1,(rd|p)>>1,row+1);
		mat[row][col]=0;
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		mat.assign(n,vector<int>(n,0));
		done=(1<<n)-1;
		solve();
	}
	return 0;
}

// solving linear recurrence// f(n)=c1*f1(n-1) + c2*f2(n-2)........+ ck*fk(n-k)
// f(n+1)=T^(n-1)f1 // (n+1)th term using matrix exponentition of linear recurrence
// spoj: 2215
#include<iostream>
#include<vector>
#define vii vector<vector<long long>> 
#define mod 1000000000 + 7
using namespace std;
typedef long long int ll;
vector<ll> a,b,c;
int k;
vii multiply(vii A,vii B){

	vii C(k+1,vector<ll>(k+1,0));
    for(int i=1; i<=k; i++){
    	for(int j=1; j<=k; j++){
           for(int x=1; x<=k; x++){
               C[i][j]=(C[i][j] + (A[i][x] * B[x][j])%mod)%mod;
           }
    	}
    }
    return C;
}
vii pow(vii &A,int p){
	if(p==1) return A;
	if(p&1){
		return multiply(A,pow(A,p-1));
	}else{
		vii X=pow(A,p/2);
		return multiply(X,X);
	}
}
ll solve(int n){
	if(n==0) 
		return 0;
	else if(n<=k)
		return b[n-1];
	vii T(k+1,vector<ll>(k+1,0));
	vector<ll> F1(k+1,0);
	for(int i=1; i<=k; i++)
		F1[i]=b[i-1];

	for(int i=1; i<=k; i++){
		for(int j=1; j<=k; j++){
			if(i<k){
				if(j==i+1)
					T[i][j]=1;
				else
					T[i][j]=0;
				continue;
			}
			T[i][j]=c[k-j];
		}
	}
	// pow(T,n-1)
    T=pow(T,n-1);
    ll result=0;
    for(int i=1; i<=k; i++)
    	result+=F1[i]*T[1][i];
    return result;
}
int main(){
	int t,n,num;
	cin>>t;
	while(t--){
		cin>>k;
	    // F1
	    for(int i=0; i<k; i++){
	    	cin>>num;
	    	b.push_back(num);
	    }
	    // cofficient
	    for(int i=0; i<k; i++){
	    	cin>>num;
	    	c.push_back(num);
	    }
	    ll ans=solve(n);
	    cout<<ans<<endl;
	    b.clear();
	    c.clear();
	}
	return 0;
}


// given a ladder we have to jump to reach above ladder 
// we can take a jump of 1,2 and 3 staris jump find the total number of ways to reach the nth stairs

//  using matrix exponentition 
#include<iostream>
#include<vector>
#define vii vector<vector<long long>> 
using namespace std;
typedef long long int ll;
vii T={{0,0,1,0},{0,0,0,1},{0,1,1,1}};
vector<ll> F1={0,3,2,1};

vii multiply(vii A,vii B){
	vii C(4,vector<ll>(4,0));
	for(int i=1; i<=4; i++){
		for(int j=1; j<=4; j++){
			for(int x=1; x<=4; x++){
				C[i][j]=C[i][j] + A[i][x] + B[x][j];
			}
		}
	}
	return C;
}
vii pow(ll p){
	if(p==1) return T;
	if(p&1)
		return multiply(A,pow(A,p-1));
	else{
		vii X=pow(A,p/2);
		return multiply(X,X);
	}

}
ll solve(ll n){
   T=pow(n-1);
   ll result=0;
   for(int i=1; i<=n; i++)
   	 result+=T[1][i]*F1[i];
   	return result;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
        ll ans=solve(n);
        cout<<ans<<endl;
	}
	return 0;
}

//gray code( mathemtics)
#include<iostream>
#include<vector>
#define next_line cout<<"\n"

using namespace std;
void solve(vector<int>& gray,int n){
	for(int i=0; i<n; i++){
		gray[i]=i^(i>>1);
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		vector<int> gray(n,0);
		solve(gray,n);
		for(int i=0; i<n; i++)
			cout<<gray[i]<<" ";
		next_line;
	}
	return 0;
}

// question based on pigion hole principle
// n poples are in n cities connected via an weihted edge find the total distance possible 
// if all people swap their position 
#include<iostream>
#include<vector>
#define vii vector<vector<pair<int,int>>> 
#define vi vector<int> 
using namespace std;
typedef long long int ll;
const ll N=1e5+10;
vii tree[N];
vi childs;
int ans=0;
void dfs(int v,int p){
	if(tree[v].size()==0) return 1;
    for(auto u: tree[v]){
    	if(u!=p){
    		childs[v]+=dfs(u,v);
    	}
    }
    return childs[v];
}
int dfs2(int v,int p){
	// main logic

}
ll solve(int n){
	dfs(1);
    return dfs2(1);
}
int solve(int v=1,)
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		childs.assign(n+1,0);
		for(int i=0; i<n-1; i++){
			int x,y,w;
			cin>>x>>y>>w;
			tree[x].push_back({y,w});
			tree[y].push_back({x,w});
		}
		int ans=solve(n);
		cout<<ans<<endl;
	}
	return 0;
}

// number therory basic
//check prime
#include<iostream>
#include<vector>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		bool flag=true;
		for(int i=2; i*i<=n; i++){
			if(n%i==0) 
				flag=false;
		}
		if(flag)
			cout<<"prime"<<endl;
		else
			cout<<"non prime"<<endl;
	}

	return 0;
}

// seive 
#include<iostream>
#include<vector>
using namespace std;
typedef long long int ll;
vector<ll> seive;
void solve(int n){
	seive.assign(n+1,1);
	seive[0]=seive[1]=-1;
    for(int i=2; i*i<=n; i++){
    	if(seive[i]==1){
    		for(int j=i*i; j<=n; j+=i)
    			seive[j]=-1;
    	}
    }
    vector<int> primes;
    for(int i=2; i<=n; i++){
    	if(seive[i]==1){
    		primes.push_back(i);
    	}
    }

    for(int i=0; i<primes.size(); i++)
    	cout<<primes[i]<<" ";
}
int main(){
	int n;
	cin>>n;
	solve(n);
	return 0;
}


// another way to implement seive // optimal then above 
#include<iostream>
#include<vector>
using namespace std;
void solve(int n){
	vector<int> seive(n,1);
	seive[0]=seive[1]=0;
	for(int i=3; i<=n; i+=2){
        if(seive[i]){
        	for(int j=i*i; j<=n; j+=i)
        		seive[j]=0;
        }
	}
	for(int i=2; i<=n; i++){
		if(seive[i] && i%2!=0)
			cout<<i<<" ";
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		solve(n);
	}
	return 0;
}

// 


// segemented seive
#include<iostream>
#include<vector>
#include<math.h>
#define next_line cout<<"\n"
using namespace std;
typedef long long int ll;
vector<ll> v;
void seive(ll b){
    ll n=sqrt(b) + 1;
    v.assign(n,1);
    v[0]=v[1]=0;
    for(ll i=2; i*i<=n; i++){
    	if(v[i]){
          for(ll j=i*i; j<=n; j+=i)
          	v[j]=0;
    	}
    }
}
void solve(ll a,ll b){
	v.clear();
    seive(b);
    vector<ll> vp(b-a+1,1);
    for(ll i=2; i*i<=b; i++){
         for(ll j=a; j<=b; j++){
            if(v[i]){
                if(j==i)
                	continue;
                else if(j%i==0)
                	vp[j-a]=0;
            }
         }
    }
    vector<ll> primes;
    for(ll i=0; i<vp.size(); i++)
    	if(vp[i] && (i+a)>1)
    	 cout<<(i+a)<<" ";

}
int main(){
	int t;
	cin>>t;
	while(t--){
		ll a,b;
		cin>>a>>b;
		solve(a,b);
		next_line;
	}
	return 0;
}


// prime factorization 
#include<iostream>
#include<vector>
#include<math.h>
#define pb push_back
using namespace std;
typedef long long int ll;
vector<ll> v;
vector<ll> seive(ll n){
	v.assign(n,0);
	v[0]=v[1]=0;
	 // mark all odd number as prime number
	for(int i=3; i<=n; i+=2)
		v[i]=1;
    
      // cut all the non prims
	for(int i=3; i<=n; i+=2){
		if(v[i]){
			for(int j=i*i; j<=n; j+=2*i)
				v[j]=0;
		}
	}
	vector<ll> primes;
	primes.pb(2);
	for(int i=3; i<=n; i+=2){
		if(v[i])
			primes.pb(i);
	}
	return primes;
}
vector<ll> solve(ll n){
	ll ans=0;
	vector<ll> p=seive(sqrt(n) + 1);
	vector<ll> res;
	ll x=p[0],i=0;
	while(x*x<=n){
		if(n%x==0){
			res.pb(x);
			while(n%x==0){
				n/=x;
			}
		}
		i++;
		x=p[i];
	}
	if(n>1)
		res.pb(n);
	return res;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> res=solve(n);
		for(auto x:res)
			cout<<x<<" ";
	}
	return 0;
}


// extended eculide algorithms
#include<iostream>
#include<vector>
using namespace std;
int x,y,gcd;
void eculide_algo(int a,int b){
	if(b==0){
		gcd=a;
		x=1,y=0;
		return ;
	}
	eculide_algo(b,a%b);
	int cx=y;
	int cy=x-(a/b)*y;
	x=cx,y=cy;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		// ax+by=gcd(a,b)
		int a,b;
		cin>>a>>b;
		eculide_algo(a,b);
		cout<<x<<" "<<y<<" "<<endl;
	}
	return 0;
}

// fast modulo exponentian  (a^n)%m=?
#include<iostream>
#include<vector>
#define ll long long
using namespace std;
ll m=1e9+7;
ll fast_moduloexp(ll a,ll b){
   ll res=1;
   while(b>0){
   	  if(b&1){
   	  	 res=(res*a)%m;
   	  }
   	  a=a*a;
   	  b>>=1;
   }
   return res;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		ll a,b;
		cin>>a>>b;
		cout<<fast_moduloexp(a,b);
	}
    return 0;
}

// multiplicative modulo inverse
#include<iostream>
#include<math.h>
#define next_line cout<<"\n"
#define ll long long 
//#define gcd(a,b) __gcd(a,b)

using namespace std;
ll x,y;
ll __gcd(ll a,ll b){
   return b==0?a:__gcd(b,a%b);
}
void eculide_algo(ll a,ll b){
   if(b==0){
       x=1,y=0;
       return;
   }
   eculide_algo(b,a%b);
   ll cx=y;
   ll cy=x-(a/b)*y;
   x=cx,y=cy;
}
ll mul_modulo_inv(ll a,ll m){
   if(__gcd(a,m)==1){
       eculide_algo(a,m);
       return (x+m)%m;
   }else{
   	 return -1;
   }
}
int main(){
	int t;
	cin>>t;
	while(t--){
		ll a,m;
		cin>>a>>m;
		cout<<mul_modulo_inv(a,m);
		next_line;
	}
	return 0;
}

// segmented seive 
#include<bits/stdc++.h>
#define ll long long 
using namespace std;
void solve(){
	ll L,R;
	cin>>L>>R;

	ll lim = sqrt(R) + 1;
	bool mark[lim + 1];
	memset(mark,false,sizeof(mark));
	vector<ll> prime;
	for(ll i=2; i<=lim; i++){
		if(!mark[i]){
			prime.push_back(i);
			for(ll j = i*i; j<=lim; j+=i){
				mark[j] = true;
			}
		}
	}

	bool isPrime[R- L + 1];
	memset(isPrime,false,sizeof(isPrime));
	for(auto i : prime){
		for(ll j= max(i*i ,(L + i - 1)/i * i); j<=R; j+=i){
			isPrime[j - L] = true;
		}
	}
	for(ll i=L; i<=R; i++){
		if(!isPrime[i-L])
			cout<<i<<" ";
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
		cout<<"\n";
	}
	return 0;
}
