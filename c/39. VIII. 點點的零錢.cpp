#include<iostream>
#include<algorithm>
using namespace std;
int n,p,*d;
pair<int,int>*x;
int main() {
	cin>>n>>p;
	x=new pair<int,int>[n];
	d=new int[p+1];
	for(int i=0;i<p;i++) {
		d[i]=-1;
	}
	d[p]=0;
	for(int i=0;i<n;i++) {
		cin>>x[i].first;
	}
	for(int i=0;i<n;i++) {
		cin>>x[i].second;
	}
	sort(x,x+n);
	for(int i=0;i<n;i++) {
		int k=min(p/x[i].first,x[i].second),num=1;
		for(;k>0;k-=num,num*=2) {
			if(num>k)num=k;
			for(int j=num*x[i].first;j<=p;j++) {
				if(d[j]!=-1) {
					d[j-num*x[i].first] = max(d[j-num*x[i].first],d[j]+num);
				}
			}
		}
		/*
		for(int j=0;j<=p;j++) {
			cout<<j<<" "<<d[j]<<endl;
		}
		cout<<endl;*/
	}
	cout<<d[0];
	return 0;
}
