#include<iostream>
using namespace std;
int ax,ay,x,y,bx,by;

int main() {
	cin>>ax>>ay>>x>>y>>bx>>by;
	
	bool yes=true;
	if( (ax <= bx && bx <= x) || (x <= bx && bx <= ax)) {}
	else yes=false;
	if( (ay <= by && by <= y) || (y <= by && by <= ay)) {}
	else yes=false;
	if(yes) cout<<"Yes";
	else cout<<"No";
	return 0;
}
