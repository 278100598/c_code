#include<iostream>
using namespace std;
int T,n,m;
int main() {
	cin>>m>>n;
	int x=0;
	for(int i=0;i<(1<<m);i++) {
		if(i!=n) x^=i;
	}
	cout<<x;
	
	/*while(T--) {
		cin>>m>>n;
		int mx=-1;
		for(int i=0;i<(1<<(1<<m));i++) {
			int s=0;
			for(int j=0;j<m;j++) {
				if(i & (1<<j)) s^=j;
			} 
			cout<<s<<endl;
			if(s==n) {
				s=0;
				for(int j=0;j<m;j++) {
					if(i & (1<<j)) s++;
				}
				mx = max(mx,s);
			}
		}
		cout<<mx;
	}*/
	
	
}
