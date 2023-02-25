#include<iostream>
#include<bitset>
#pragma GCC optimize("O3")
#define endl "\n"
using namespace std;

int N,M;
bitset<10001> all[201],inter[201][201];

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>N;
	M=((N*(N-1))/2);
	for(int i=0;i<M;i++) {
		int x,y,k;
		cin>>x>>y>>k;
		for(int j=0;j<k;j++) {
			int t;
			cin>>t;
			inter[x][y][t]=true;
			inter[y][x][t]=true;
			all[x][t]=true;
			all[y][t]=true;
		}
	}
	
	for(int i=1;i<=200;i++) {
		for(int j=1;j<=200;j++) {
			if(i==j) continue;
			
			for(int k=1;k<=10000;k++) {
				if(all[i][k] && all[j][k] && !inter[i][j][k]) {
					cout<<"No";
					return 0;
				} else if((!all[i][k] || !all[j][k]) && inter[i][j][k]) {
					cout<<"No";
					return 0;
				}
			}
		}
	}
	cout<<"Yes"<<endl;
	for(int i=1;i<=N;i++) {
		cout<<all[i].count();
		for(int j=1;j<=10000;j++) {
			if(all[i][j]) cout<<" "<<j;
		}
		cout<<endl;
	}
	
	return 0;
}

