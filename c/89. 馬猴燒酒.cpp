#include<iostream>
#include<map>
using namespace std;
int *x,k,n,z;
map<int,int> *a,*b;

void dfs(int index,int end,int kk,int s,map<int,int> *m) {
	if(index == end) {
		m[kk][s]++;
		return;
	}
	long long int ss = s;
	dfs(index+1,end,kk,(ss+x[index])%z,m);
	if(kk>=1) {
		ss = x[index];
		dfs(index+1,end,kk-1,(s+ss*ss)%z,m);
	}
	if(kk>=2) {
		ss = x[index];
		dfs(index+1,end,kk-2,(s+2*ss+3)%z,m);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>k>>z;
	x = new int[n];
	a = new map<int,int>[k+1];
	b = new map<int,int>[k+1];
	for(int i=0;i<n;i++) {
		cin>>x[i];
	}
	
	dfs(0,n/2,k,0,a);
	dfs(n/2,n,k,0,b);
	
	int sum=0;
	for(int i=0;i<=k;i++) {
		/*
		cout<<"a"<<endl;
		for(auto it=a[i].begin();it!= a[i].end();it++) {
			cout<<i<<" "<<it->first<<" "<<it->second<<endl;
		}
		cout<<"b"<<endl;
		for(auto it=b[i].begin();it!= b[i].end();it++) {
			cout<<i<<" "<<it->first<<" "<<it->second<<endl;
		}
		cout<<endl;*/
		for(auto it=a[i].begin();it!=a[i].end();it++) {
			for(int j=k-i;j<=k;j++) {
				auto it2 = b[j].find(z-it->first);
				if(it2 != b[j].end()) {	
					sum+=it2->second*it->second;
				}
			}
		}
	}
	cout<<sum;
	return 0;
}

