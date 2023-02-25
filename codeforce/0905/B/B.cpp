#include<iostream>
using namespace std;
long long int T,W,X,Y,D,ans=0,S,tmp,tmp1;
int main() {
	cin>>W>>X>>Y>>T>>D;
	S = W-T;
	if(S==0){
        cout<<0<<endl;
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
		cout<<ans<<endl;
		return 0;
	}
	ans = 8-D;

	if(S+X>6*Y)tmp=S/(6*Y-X);
	else tmp=0;

	ans+=tmp*7;
	if((S+X-tmp*(6*Y-X))%Y>0)tmp1=1;
	else tmp1=0;

	ans+=tmp1+(S+X-tmp*(6*Y-X))/Y;

	cout<<ans<<endl;
	return 0;
}


