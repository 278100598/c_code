#include<iostream>
using namespace std;
#define x first
#define y second
typedef pair<long long int,long long int> PII;
long long int cross(PII a, PII b, PII c){
	return (b.x - a.x) *  (c.y - a.y) - (b.y - a.y) *  (c.x - a.x);
}

PII O[50];
int N,P;
long long int ans=0;

int main () {
	cin>>N;
	while(N--) {
		long long int t=0;
		cin>>P;
		for(int i=0;i<P;i++) {
			cin>>O[i].x>>O[i].y;
		}
		t+=cross(PII(0,0),O[P-1],O[0]);
		for(int i=1;i<P;i++) {
			t+=cross(PII(0,0),O[i-1],O[i]);
		}
		ans+=abs(t);
	}
	cout<<ans/2<<endl;
	return 0;
}
