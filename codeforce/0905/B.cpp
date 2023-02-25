#include<iostream>
using namespace std;
long long int T,W,X,Y,D,ans=0,S;
int main() {
	cin>>W>>X>>Y>>T>>D;
	S = W-T;
	
	if(S==0) {
		cout<<0;
		return 0;
	} 
	for(int i=0;D+i<=6;i++) {
		S-=Y;
		if(S <= 0) {
			ans=i+1;
			break;
		}
	}
	if(ans != 0) {
		cout<<ans;
		return 0;
	}
	ans = 8-D;
	S+=X;
	
	
	long long int diff = S-(6*Y);
	if(diff>0) {
		ans += ((diff-1)/(6*Y-X)+1) * 7;
		S -= ((diff-1)/(6*Y-X)+1) * (6*Y-X);
	}
	
	for(int i=1;i<=6;i++) {
		S-=Y;
		if(S <= 0) {
			ans+=i;
			break;
		}
	}
	
	cout<<ans;
	return 0;
}

/*
10 5 1 7 6
*/
