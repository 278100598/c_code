#include<iostream>
using namespace std;
int go()
{ 
	long long int wl,dl,wr,dr;
	cin>>wl>>dl>>wr>>dr;
	if(wl==0)
	{
		wl=go();
	}
	if(wr==0)
	{
		wr=go();
	}
	if(wl==-1||wr==-1)
	{
		return -1;
	}
	else if(wl*dl==wr*dr)
	{
		return wl+wr;
	}
	else
	{
		return -1;
	}
}
int main()
{
	long long int x;
	x=go();
	cout<<(x==-1?"NO":"YES");
	return 0;
}
