#include<iostream>
#include<bitset>
using namespace std;
long long int N,M,MOD=1000000000;
long long int e[(1<<8)][(1<<8)],ans[(1<<8)],t[(1<<8)][(1<<8)];

void init(int x,int two,int index) {
	//cout<<x<<" "<<index<<endl;
	if(index==N) {
		for(int i=0;i<(1<<N);i++) {
			if((x&i)==0 && (two&i)==0) {
				e[i][x]++;
			}
		}
		return;
	}
	
	if(index+2<=N) init((x<<2),(two<<2)+3,index+2);
	init((x<<1),(two<<1),index+1);
	init((x<<1)+1,(two<<1),index+1);
}

void up() {
	for(int i=0;i<(1<<N);i++) {
		for(int j=0;j<(1<<N);j++) t[i][j]=0;
	}
	
	for(int i=0;i<(1<<N);i++) {
		for(int j=i;j<(1<<N);j++) {
			long long int s=0;
			for(int k=0;k<(1<<N);k++) {
				s += (e[i][k] * e[k][j]);
				s %= MOD;
			}
			t[i][j]=s;
			t[j][i]=s;
		}
	}
	
	for(int i=0;i<(1<<N);i++) {
		for(int j=0;j<(1<<N);j++) {
			e[i][j]=t[i][j];
		}
	}
}

void mul() {
	for(int i=0;i<(1<<N);i++) t[i][i]=0;
	for(int i=0;i<(1<<N);i++) {
		for(int j=0;j<(1<<N);j++) {
			t[j][j]+=(ans[i]*e[i][j]);
			t[j][j]%=MOD;
		}
	}
	for(int i=0;i<(1<<N);i++) ans[i]=t[i][i];
}

int main() {
	cin>>N>>M;
	
	for(int i=0;i<(1<<N);i++) {
		for(int j=0;j<(1<<N);j++) {
			e[i][j]=0;
			t[i][j]=0;
		}
		ans[i]=0;
	}
	init(0,0,0);
	ans[0]=1;
	
	while(M>0) {
		if(M%2==1) {
			mul();
		}
		up();
		M/=2;
	}
	
	cout<<ans[0];
	
	/*
	for(int i=0;i<(1<<N);i++) {
		for(int j=0;j<(1<<N);j++) {
			bitset<8>a(i),b(j);
			cout<<a<<" "<<b<<" "<<e[i][j]<<endl;
			
		}
	}*/
	
	return 0;
} 
