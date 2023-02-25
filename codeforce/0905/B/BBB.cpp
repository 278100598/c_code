#include<iostream>
using namespace std;
long long int T,W,X,Y,D,ans=0,S;
int main() {
	cin>>W>>X>>Y>>T>>D;
	
	while(W > T) {
		if(D==7) {
			W+=X; 
			D=1;
		} else {
			W-=Y;
			D++;
		}
		ans++;
	}
	
	cout<<ans<<endl;
	
	return 0;
}

/*
10 5 1 7 6
*/
