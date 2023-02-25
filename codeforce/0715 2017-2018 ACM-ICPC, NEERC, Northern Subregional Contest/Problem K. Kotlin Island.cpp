#include<iostream>
#include<math.h>
using namespace std;
int main() {
	freopen("kotlin.in","r",stdin);    // Åª file.in ÀÉ
	freopen("kotlin.out","w",stdout);  // ¼g¤J file.out ÀÉ
	int h,w,n,x,y;
	bool yes=false;
	cin>>h>>w>>n;
	for(int i=1;i<=sqrt(n);i++) {
		if(n%i==0) {
			int a=n/i;
			if(a*2-1<=h&&i*2-1<=w) {
				yes=true;
				x=i;
				y=a;
				break;
			}
			if(i*2-1<=h&&a*2-1<=w) {
				yes=true;
				x=a;
				y=i;
				break;
			}
		}
	}
	if(yes) {
		x--;
		y--;
		for(int i=0;i<h;i++) {
			int xx=x;
			for(int j=0;j<w;j++) {
				if((j%2==1&&xx>0)||(i%2==1&&y>0)) {
					cout<<'#';
					xx--;
				}
				else cout<<'.';
			}
			cout<<endl;
			if(i%2==1&&y>0) y--;
		}
	} else {
		cout<<"Impossible";
	}
	return 0;
}
