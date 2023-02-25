#include<iostream>
using namespace std;
int main() {
	int d;
	cin>>d;
	for(int t=1;t<=d;t++) {
		int n,s,mx=-1000000001;
		cin>>n>>s;
		for(int i=0;i<n;i++) {
			int f,t;
			cin>>f>>t;
			if(s<t) {
				f-=(t-s);
			}
			mx = max(f,mx);
		}
		cout<<"Case #"<<t<<": "<<mx<<endl; 
	}
	
	return 0;
}
