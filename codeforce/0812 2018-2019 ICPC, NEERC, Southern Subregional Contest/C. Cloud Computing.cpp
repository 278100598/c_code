#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long int
using namespace std;

struct CPU{
	ll price=0,num=0;
	CPU(){};
	CPU(ll c,ll p) {
		price=p;
		num=c;
	}
};
int N,K,M,cnt=0;
vector<CPU> op[1000002],ed[1000002];
CPU tree[4*1000002];
ll ans=0;

void add(int index,int l,int r,ll c,ll p) {
	//cnt++;
	tree[index].num += c;
	tree[index].price += c * p;
	if(l==r) return;
	int m=(l+r)/2;
	if(p<=m) {
		add(index*2,l,m,c,p);
	} else {
		add(index*2+1,m+1,r,c,p);
	}
}

void go(int index,int l,int r,ll need) {
	//cnt++;
	//cout<<l<<" "<<r<<" "<<need<<" "<<tree[index].num<<endl;
	if(tree[index].num <= need) {
		ans += tree[index].price;
		return;
	}
	if(l==r) {
		ans+= l*need;
		return;
	}
	int m=(l+r)/2;
	go(index*2, l, m, need);
	if(tree[index*2].num <need) {
		go(index*2+1, m+1, r, need - tree[index*2].num);
	}
}

int main() {
	cin>>N>>K>>M;
	
	for(int i=0;i<M;i++) {
		int from,to,c,p;
		cin>>from>>to>>c>>p;
		op[from].push_back(CPU(c,p));
		ed[to+1].push_back(CPU(c,p));
	}
	
	for(int i=1;i<=N;i++) {
		for(CPU cpu:op[i]) add(1, 1, 1000000, cpu.num, cpu.price);
		for(CPU cpu:ed[i]) add(1, 1, 1000000, -cpu.num, cpu.price);
		
		go(1,1,1000000,K);
	}
	
	cout<<ans;//<<" "<<cnt;
	return 0;
}
/*
10000 700 5
1 10000 1 1
1 10000 1 2
1 10000 1 3
1 10000 1 4
1 10000 1 5*/ 
