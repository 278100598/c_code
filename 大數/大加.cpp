#include <bits/stdc++.h>
#include <string>
using namespace std;
string bigadd(string x,string y)
{
	if(y.size()>x.size())
	{
		string c=x;
		x=y;
		y=c;
	}
	int b[x.size()+1],lx=x.size(),ly=y.size();
	for(int i=0;i<=lx;i++)
	{
		b[i]=0;
	}
	string a="";
	int carry=0;
	for(int i=0;i<lx;i++)
	{
		if(i>ly-1)
		{
			int tt=((int(x[lx-i-1])-48)+carry)/10;
			b[i]=((int(x[lx-i-1])-48)+carry)%10;
			carry=tt;
		}
		else
		{
			int tt=((int(y[ly-i-1])-48)+(int(x[lx-i-1])-48)+carry)/10;
			b[i]=((int(y[ly-i-1])-48)+(int(x[lx-i-1])-48)+carry)%10;
			carry=tt;
		}
		//cout<<i<<" "<<b[i]<<" "<<(int(y[ly-i-1])-48)+(int(x[lx-i-1])-48)<<" "<<carry<<endl;	
	}
	b[lx]+=carry;
	int tg=0;
	for(int i=lx;i>=0;i--)
	{
		if(b[i]!=0)
		{
			tg=i;
			break;
		}
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
	a=bigadd(a,b);
	cout<<a;
	return 0;
} 
