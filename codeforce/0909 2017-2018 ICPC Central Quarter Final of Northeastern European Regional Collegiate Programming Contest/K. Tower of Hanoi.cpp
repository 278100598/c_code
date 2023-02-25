#include<iostream>
#include<bitset>
using namespace std;
int N,M,ans=1;
string s="";
bitset<1000> cnt,mx;
void TT(char x,char y,char z,int n) {
	if(n==0) return;
	if(s[n-1] == x) {
		cnt[N-n] = false;
		TT(x,z,y,n-1);
	} else if(s[n-1] == y) {
		cnt[N-n] = true;
		TT(z,y,x,n-1);
	}
}
/*
void Tower(char x,char y,char z,int n) {
	if(n==0) {
		cout<<s<<endl;
		ss = s;
		TT('A','B','C',N);
		cout<<ss<<endl;
		return;	
	}
	Tower(x,z,y,n-1);
	s[n-1] = y;
	Tower(z,y,x,n-1);
}*/


int main() {
	cin>>N>>M;
	mx=0;
	for(int i=1;i<=M;i++) {
		cin>>s;
		TT('A','B','C',N);
		
		for(int j=0;j<N;j++) {
			if(cnt[j] && !mx[j]) {
				mx=cnt;
				ans=i;
				break;
			} else if(!cnt[j] && mx[j]) break;
		}
	}
	cout<<ans;
	
	return 0;
}
