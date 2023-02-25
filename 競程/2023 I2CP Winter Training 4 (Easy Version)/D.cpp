#include<iostream>
using namespace std;
long long int A,L;

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int t=1;
	while(cin>>A>>L) {
		if(A<0 && L<0) break;
		
		int cnt=1;
		for(long long int x=A;;cnt++) {
			if(x==1) break;
			else if(x%2==0) x/=2;
			else x = x*3+1;
			
			if(x>L) break;
		}
		
		printf("Case %d: A = %lld, limit = %lld, number of terms = %lld\n",t++,A,L,cnt);
	}
	
	return 0;
}
