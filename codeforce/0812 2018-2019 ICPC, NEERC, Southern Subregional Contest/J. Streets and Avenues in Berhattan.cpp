#include<iostream>
#include<bitset>
using namespace std;
long long int keep[26],T;
bitset<200001> d;

int main() {
	cin>>T;
	while(T--) {
		for(int i=0;i<26;i++) keep[i]=0;
		int N,M,K;
		long long int mn=1e11;
		cin>>N>>M>>K;
		//if(M>N) swap(N,M);
		for(int i=0;i<K;i++) {
			char c;
			cin>>c;
			keep[c-'A']++;
		}
		
		d=0;
		d[0]=true;
		for(int i=0;i<26;i++) {
			for(int j=K-keep[i];j>=0;j--) {
				if(d[j]) d[j+keep[i]] = true;
			}
		}
		for(int i=N;K-i>=M;i++) {
			if(d[i]) mn=0;
		}
		
		for(int i=0;i<26 && mn!=0;i++) {
			d=0;
			d[0]=true;
			for(int ii=0;ii<26;ii++) {
				if(i==ii) continue;
				for(int j=K-keep[ii];j>=0;j--) {
					if(d[j]) d[j+keep[ii]] = true;
				}
			}
			
			//for(int i=0;i<=N+M;i++)cout<<d[i];
			//cout<<endl;
			
			for(int j=max(K-keep[i]-M,0LL);j<=N;j++) {
				if(d[j]) mn = min(mn,(N-j)*(M-(K-keep[i]-j)));
			}
		}
		cout<<mn<<'\n';
	}
	
	return 0;
}
