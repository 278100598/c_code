#include<iostream>
#include<algorithm>
using namespace std;
int N,s[1000];

int main() {
	cin>>N;
	for(int i=0;i<N;i++) cin>>s[i];
	sort(s,s+N);
	
	bool y=true;
	int mn=s[0];
	for(int i=1;i<N;i++) {
		if(s[i]%mn != 0) {
			y=false;
			break;
		}
	}
	
	if(y) {
		if(N==1) {
			cout<<N<<'\n'<<s[0];
		} else {
			cout<<2*(N-1)<<'\n';
			for(int i=1;i<N;i++) {
				cout<<mn<<' '<<s[i]<<' ';
			}
		}
	} else {
		cout<<-1;
	}
	
	return 0;
}
