#include<iostream>
#include<cMath>
#include<iomanip>
using namespace std;
long long int tree[400000],a[100000],b[100000],N,M;

void add(int index,int begin,int end,int l,int r,long long int num) {
	//cout<<begin<<" "<<end<<" "<<l<<" "<<r<<" "<<index<<"\n";
	tree[index] += num;
	if(l==r) return;
	
	int m=(l+r)/2;
	if(begin <= m) add((index<<1),begin,end,l,m,num);
	if(m+1 <= end) add((index<<1)+1,begin,end,m+1,r,num);
}

long long int find(int index,int begin,int end,int l,int r) {
	if(begin <= l && r <= end) return tree[index];
	long long int sum=0;
	
	int m=(l+r)/2;
	if(begin <= m) sum+=find((index<<1),begin,end,l,m);
	if(m+1 <= end) sum+=find((index<<1)+1,begin,end,m+1,r);
	return sum;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin>>N;
	//for(int i=0;i<4*N;i++) tree[i]=0;
	for(int i=0;i<N;i++) cin>>a[i];
	for(int i=0;i<N;i++) cin>>b[i];
	for(int i=0;i<N;i++) {
		add(1,i,i,0,N-1,(a[i]-b[i])*(a[i]-b[i]));
	}
	
	cin>>M;
	for(int i=0;i<M;i++) {
		int ll,rr;
		cin>>ll>>rr;
		cout<<fixed<<setprecision(6)<<sqrt(find(1,ll-1,rr-1,0,N-1))<<'\n';
		//cout<<find(1,ll-1,rr-1,0,N-1)<<'\n';
	}
	return 0;
}
/*
5
1 2 3 4 5
1000 1 2 1 1
3
1 4
2 5
1 3

*/
