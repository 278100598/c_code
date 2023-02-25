#include<iostream>
#include<math.h>
using namespace std;
long long int N;
int main() {
	while(cin>>N) {
		if(N==0) break;
		long long int rt=sqrt(N);
		
		if(rt*rt==N) cout<<"yes\n";
		else cout<<"no\n";
	}
	
	return 0;
}
