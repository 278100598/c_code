#include <bits/stdc++.h>
#include <string>
using namespace std;
string bigsubtract(string x,string y)
{
	bool nega=false;
	if(y.size()>x.size()||(y>x&&y.size()==x.size()))
	{
		string c=x;
		x=y;
		y=c;
		nega=true;
	}
	int b[x.size()],lx=x.size(),ly=y.size();
	for(int i=0;i<lx;i++)
	{
		b[i]=0;
		if(ly<=i)
		{
			y="0"+y;
		}
	}
	string a="";
	int carry=0;
	for(int i=0;i<lx;i++)
	{
		b[i]=((int(x[lx-i-1])-48)-(int(y[lx-i-1])-48)+carry+10)%10;
		if((int(x[lx-i-1])-48)-(int(y[lx-i-1])-48)+carry<0)
		{
			carry=-1;
		}
		else
		{
			carry=0;
		}
		//cout<<i<<" "<<b[i]<<" "<<(int(x[lx-i-1])-48)<<" "<<(int(y[lx-i-1])-48)<<" "<<carry<<endl;	
	}
	b[lx]+=carry;
	int tg;
	for(int i=lx-1;i>=0;i--)
	{
		tg=i;
		if(b[i]!=0)
		{
			break;
		}
	}
	if(nega)
	{
		a+="-";
	}
	for(int i=tg;i>=0;i--)
	{
		a+=char(b[i]+48);
	}
	return a;
}
int main()
{
	string a,b;
	cin>>a>>b;
	a=bigsubtract(a,b);
	cout<<a;
	return 0;
}
