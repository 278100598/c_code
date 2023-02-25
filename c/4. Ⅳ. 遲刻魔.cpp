#include<iostream>
using namespace std;
int main()
{
	int h;
	float x,y;
	cin>>h>>x>>y;
	y-=7.5;
	y/=15;
	x-=7.5;
	x/=15;
	if(x<0)x--;
	if(y<0)y--;
	//cout<<static_cast<int>(x)<<" "<<static_cast<int>(y)<<endl;
	cout<<(h+(static_cast<int>(y)-static_cast<int>(x))+24)%24<<" o'clock";
	return 0;
}
