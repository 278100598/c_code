#include<bits/stdc++.h>
using namespace std;
long long int T,N,x[3],sum=0,total;

long long int get(long long int a,long long int b) {
	if(b < a) return 0;
	return (b-a+1)*(a+b)/2;
}

int main() {
	cin>>T;
	while(T--) {
		total = 0;
		sum = 0;
		cin>>N>>x[0]>>x[1]>>x[2];
		sort(x,x+3);
		if(N < x[0]) {
			cout<<"0\n";
			continue;
		}
		
		int l=0,r=x[1]-x[0]-1;
		if(N < get(x[0],x[0]+r)) {
			while(l!=r) {
				int m=l+r;
				if(m%2==1) m=m/2+1;
				else m/=2;
				if(N < get(x[0],x[0]+m)) r=m-1;
				else l=m;
			}
			cout<<l+1<<'\n';
			continue;
		}
		sum += r+1;
		total += get(x[0],x[0]+r);
		
		if(N < total + x[1]*2) {
			if(total + x[1] <= N) cout<<sum+1<<'\n';
			else cout<<sum<<'\n';
			continue;
		}
		
		l=0,r=x[2]-x[1]-1;
		if(N < total+get(x[1],x[1]+r)*2) {
			while(l!=r) {
				int m=l+r;
				if(m%2==1) m=m/2+1;
				else m/=2;
				if(N < total + get(x[1],x[1]+m)*2) r=m-1;
				else l=m;
			}
			if(total + get(x[1],x[1]+l)+x[1]+l+1 <= N) cout<<sum+(l+1)*2+1<<'\n';
			else cout<<sum+(l+1)*2<<'\n';
			continue;
		}
		sum += (r+1)*2;
		total += get(x[1],x[1]+r)*2;
		
		if(N < total + x[2]*3) {
			if(total + x[2]*2 <= N) cout<<sum+2<<'\n';
			else if(total + x[2] <= N) cout<<sum+1<<'\n';
			else cout<<sum<<'\n';
			continue;
		}
		
		l=0,r=1e6;
		while(l!=r) {
			int m=l+r;
			if(m%2==1) m=m/2+1;
			else m/=2;
			if(N < total + get(x[2],x[2]+m)*3) r=m-1;
			else l=m;
		}
		if(total + get(x[2],x[2]+l)*3+(x[2]+l+1)*2 <= N) cout<<sum+(l+1)*3+2<<'\n';
		else if(total + get(x[2],x[2]+l)*3+x[2]+l+1 <= N) cout<<sum+(l+1)*3+1<<'\n';
		else cout<<sum+(l+1)*3<<'\n';
	}
	return 0;
}
/*
6
3 2 2 5
*/
