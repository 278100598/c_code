#include<iostream>
using namespace std;
int main() {
	freopen("intel.in","r",stdin);    // Ū file.in ��
	freopen("intel.out","w",stdout);  // �g�J file.out ��
	int n,x,y,nx,ny;
	cin>>n>>x>>y;
	int mxx=x,mxy=y,mnx=x,mny=y,total=0;
	int xx=x,yy=y;
	for(int i=1;i<n;i++) {
		cin>>nx>>ny;
		mxx=max(mxx,nx);
		mxy=max(mxy,ny);
		mnx=min(mnx,nx);
		mny=min(mny,ny);
		total+=abs(nx-x);
		total+=abs(ny-y);
		x=nx;
		y=ny;
	}
	total+=abs(nx-xx);
	total+=abs(ny-yy);
	cout<<(total-(mxx-mnx)*2-(mxy-mny)*2);
	return 0;
} 
