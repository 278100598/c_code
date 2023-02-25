#include<iostream>
using namespace std;
long long int **x,*m,n;
long long int bfs(int begin,int end) {
	if(x[begin][end]!=-1)return x[begin][end];
	if(begin+1==end) return m[begin]+m[end];
	if(begin==end) return m[end];
	long long int mn=10000000000000;
	for(int i=begin+1;i<end;i++) {
		mn=min(max(bfs(begin+1,i),bfs(i+1,end)),mn);
	}
	x[begin][end]=m[begin]+mn;
	//cout<<begin<<" "<<end<<" "<<mn<<endl;
	return x[begin][end];
}
int main() {
	cin>>n;
	x = new long long int*[n];
	m = new long long int[n];
	long long int mx=0;
	for(int i=0;i<n;i++){
		x[i]=new long long int[n];
		for(int j=0;j<n;j++) x[i][j]=-1;
		cin>>m[i];
		mx+=m[i];
	}
	
	cout<<bfs(0,n-1)<<" "<<mx;
	
	return 0;
}
