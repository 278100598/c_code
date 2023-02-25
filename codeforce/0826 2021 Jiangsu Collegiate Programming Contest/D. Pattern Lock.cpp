#include<iostream>
using namespace std;
int n,m;

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	
	if(n%2 == 0) {
		int x=1;
		while(x+1 <= n) {
			cout<<x<<" "<<1<<endl;
			cout<<x<<" "<<2<<endl;
			for(int i=1;i<m-1;i++) {
				cout<<x+1<<" "<<i<<endl;
				cout<<x<<" "<<i+2<<endl;
			}
			cout<<x+1<<" "<<m-1<<endl;
			cout<<x+1<<" "<<m<<endl;
			x+=2;
		}
	} else {
		int x=1,y=1;
		while(x+1 <= n-3) {
			cout<<x<<" "<<1<<endl;
			cout<<x<<" "<<2<<endl;
			for(int i=1;i<m-1;i++) {
				cout<<x+1<<" "<<i<<endl;
				cout<<x<<" "<<i+2<<endl;
			}
			cout<<x+1<<" "<<m-1<<endl;
			cout<<x+1<<" "<<m<<endl;
			x+=2;
		}
		
		
		if(m==3) {
			cout<<x<<" "<<1<<endl;
			cout<<x+1<<" "<<3<<endl;
			cout<<x+2<<" "<<1<<endl;
			cout<<x<<" "<<2<<endl;
			cout<<x+2<<" "<<3<<endl;
			cout<<x+1<<" "<<1<<endl;
			cout<<x<<" "<<3<<endl;
			cout<<x+2<<" "<<2<<endl;
			cout<<x+1<<" "<<2<<endl;
			return 0;
		}
		cout<<x<<" "<<1<<endl;
		cout<<x<<" "<<2<<endl;
		cout<<x+2<<" "<<1<<endl;
		cout<<x+1<<" "<<2<<endl;
		cout<<x+1<<" "<<1<<endl;
		cout<<x+2<<" "<<2<<endl;
		y+=2;
		
		if(m%2==0) {
			while(y+1 <= m) {
				cout<<x<<" "<<y<<endl;
				cout<<x+1<<" "<<y<<endl;
				cout<<x<<" "<<y+1<<endl;
				cout<<x+2<<" "<<y<<endl;
				cout<<x+1<<" "<<y+1<<endl;
				cout<<x+2<<" "<<y+1<<endl;
				y+=2;
			}
		} else {
			while(y+1 <= m-3) {
				cout<<x<<" "<<y<<endl;
				cout<<x+1<<" "<<y<<endl;
				cout<<x<<" "<<y+1<<endl;
				cout<<x+2<<" "<<y<<endl;
				cout<<x+1<<" "<<y+1<<endl;
				cout<<x+2<<" "<<y+1<<endl;
				y+=2;
			}
			
			cout<<x<<" "<<y<<endl;
			cout<<x+2<<" "<<y+1<<endl;
			cout<<x<<" "<<y+2<<endl;
			cout<<x+1<<" "<<y<<endl;
			cout<<x+2<<" "<<y+2<<endl;
			cout<<x<<" "<<y+1<<endl;
			cout<<x+2<<" "<<y<<endl;
			cout<<x+1<<" "<<y+2<<endl;
			cout<<x+1<<" "<<y+1<<endl;
		}
	}
	
	
	return 0;
}
