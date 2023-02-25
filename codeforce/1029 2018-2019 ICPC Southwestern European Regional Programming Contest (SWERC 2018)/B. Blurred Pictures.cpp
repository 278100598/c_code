#include<iostream>
#define mp make_pair
#define F first
#define S second
using namespace std;
int N,tag[400000],mn,mx,now=0;
pair<int,int> tree[400000];
bool z[400000];

void zero(int begin,int end,int l,int r,int index) {
	if(begin <= l && r <= end) {
		z[index] = true;
		tag[index]=0;
		return;
	}
	if(l==r) return;
	
	int m=(l+r)/2;
	if(begin<=m) zero(begin,end,l,m,index*2);
	if(m+1<=end) zero(begin,end,m+1,r,index*2+1);
	
}

void add(int begin,int end,int l,int r,int index) {
	if(begin <= l && r <= end) {
		tag[index]++;
		return;
	}
	if(l==r) return;
	
	int m=(l+r)/2;
	if(begin<=m) add(begin,end,l,m,index*2);
	if(m+1<=end) add(begin,end,m+1,r,index*2+1);
}

void find(int begin,int end,int l,int r,int index) {
	tree[index].F += tag[index];
	tree[index].S += tag[index];
	if(l!=r) {
		tag[index*2] = tag[index];
		tag[index*2+1] = tag[index];
	}
	tag[index] = 0;
	
	
	
	
}

int main() {
	cin>>N;
	for(int i=0;i<N;i++) {
		int a,b;
		cin>>a>>b;
		if(1<=a) zero(0,a-1,0,N-1,1);
		if(b<=N-2) zero(b+1,N-1,0,N-1,1);
		
		mn=1e9;
		mx=-1e9;
		add(a,b,0,N-1,1);
		if(mx-mn+1>=now+1) now++;
		//cout<<mn<<' '<<mx<<'\n';
		//cout<<now<<'\n';
	}
	cout<<now;
	
	return 0;
}
