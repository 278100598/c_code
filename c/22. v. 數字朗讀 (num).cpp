#include<iostream>
using namespace std;
string z[20]={"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
string ten[10]={"","","twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
void go(int x,bool &f)
{
	int y=x/100;
	if(y!=0)
	{
		cout<<(f?"":" ")<<z[y]<<" hundred";
		f=false;
	}
	y=(x%100);
	bool tt=false;
	if(y>=20)
	{
		cout<<(f?"":" ")<<ten[y/10];
		tt=true;
		f=false;
		y%=10;
	}
	if(y!=0)
	{
		cout<<(f?"":(tt?"-":" "))<<z[y];
	}
	f=false;
}
int main()
{
	bool f=true;
	int x,y;
	cin>>x;
	if(x==0)cout<<"zero";
	if(x<0)
	{
		cout<<"minus";
		x*=-1;
		f=false;
	}
	y=x/1000000000;
	if(y!=0)
	{
		go(y,f);
		cout<<" billion";
	}
	y=(x%1000000000)/1000000;
	if(y!=0)
	{
		go(y,f);
		cout<<" million";
	}
	y=(x%1000000)/1000;
	if(y!=0)
	{
		go(y,f);
		cout<<" thousand";
	}
	y=x%1000;
	if(y!=0)go(y,f);
	return 0;
}
