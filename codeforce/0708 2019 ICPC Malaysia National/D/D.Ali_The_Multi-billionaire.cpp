#include<iostream>
#define Ps pair<long long int,long long int>
#define a first
#define b second
#define ll long long int 
using namespace std;
const ll MOD=100007;

void muti(ll **a,ll **b,int size) {
	ll x[size][size];
	for(int i=0;i<size;i++) {
		for(int j=0;j<size;j++) {
			ll t=0;
			for(int k=0;k<size;k++) {
				ll aa=a[i][k],bb=b[k][j];
				t+=(aa*bb);
			}
			t%=MOD;
			x[i][j]=t;
		}
	}
	for(int i=0;i<size;i++) {
		for(int j=0;j<size;j++) a[i][j]=x[i][j];
	}
}
int f(long long int a,long long int b) {
	b%=7;
	if(a<=b) return 1;
	if(b==0) return 0;
	if(b==1) return 1;
	
	ll **e=new ll*[b],**x=new ll*[b];
	for(int i=0;i<b;i++) {
		e[i]=new ll[b];
		e[i][0]=1;
		x[i]=new ll[b];
		x[i][0]=1;
	}
	for(int i=1;i<b;i++) {
		for(int j=0;j<b;j++) {
			e[j][i]=(i<=j?1:0);
			for(int k=0;k<i;k++) e[j][i]+=e[j][k];
			x[j][i]=e[j][i];
		}
	}
	
	a-=(b+1);
	int m=a%b;
	a/=b;
	while(a>0) {
		if(a%2==1) muti(x,e,b);
		muti(e,e,b);
		a/=2;
		/*
		for(int i=0;i<b;i++) {
			for(int j=0;j<b;j++) {
				cout<<x[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;*/
	}
	ll sum=0;
	for(int i=0;i<b;i++) sum+=x[i][m];
	return sum%MOD;
}

ll total=0;
int N,M;
Ps *tree;

void addt(int begin,int end,int l,int r,ll index,bool adda,ll num) {
	if(end<l||r<begin)return;
	if(begin<=l && r<=end) {
		//cout<<l<<" "<<r<<" "<<index<<endl;
		if(adda) tree[index].a += num;
		else tree[index].b += num;
		return;
	}
	
	int m =(l+r)>>1;
	addt(begin,end,l,m,index*2,adda,num);
	addt(begin,end,m+1,r,index*2+1,adda,num);
}
void go(int l,int r,ll index,ll suma,ll sumb) {
	if(l>=r) {
		ll aa=(suma+tree[index].a),bb=(sumb+tree[index].b);
		//cout<<l<<" "<<aa<<" "<<bb<<" "<<f(aa,bb)<<endl;
		total += f(aa,bb);
		return;
	}
	
	int m=(l+r)>>1;
	go(l,m,index*2,suma+tree[index].a,sumb+tree[index].b);
	go(m+1,r,index*2+1,suma+tree[index].a,sumb+tree[index].b);
	
}

int X=0;

int main() {
	cin>>N>>M;
	tree = new Ps[N*8];
	for(int i=0;i<N*8;i++) tree[i]=Ps(0,0);
	tree[1]=Ps(1,1);
	
	for(int i=0;i<M;i++) {
		char c;
		int j,k,h;
		cin>>c>>j>>k>>h;
		j+=X;
		k+=X;
		if(j<=k) {
			addt(j,k,1+X,N+X,1,(c=='a'),h);
		} else {
			addt(1+X,k,1+X,N+X,1,(c=='a'),h);
			addt(j,N+X,1+X,N+X,1,(c=='a'),h);
		}
	}
	
	
	go(1+X,N+X,1,0,0);
	
	cout<<total;
	return 0;
}
