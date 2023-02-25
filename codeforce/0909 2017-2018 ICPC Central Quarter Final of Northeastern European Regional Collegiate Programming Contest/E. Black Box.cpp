#include<iostream>
#include<bitset>
using namespace std;
int N;
bitset<1000000> ans,init;
int main() {
	cin>>N;
	for(int i=0;i<N;i++) {
		char c;
		cin>>c;
		init[i]=(c=='1');
	}
	
	int add=0,count=0;
	for(int i=0;i<N;i++) {
		if(init[i]) count++;
		
		int now = count+add;
		add = now>>1;
		
		ans[i]=(now & 1);
	}
	
	for(int i=0;i<N;i++) {
		cout<<(ans[i]?1:0);
	}
	
	return 0;
}
