#include <bits/stdc++.h>
#include <string>
using namespace std;
string bigmultiply(string x,string y)
{
	int b[x.size()+y.size()],lx=x.size(),ly=y.size();
	for(int i=0;i<lx+ly;i++)
	{
		b[i]=0;
	}
	string a="";
	int cc=0;
	for(int i=0;i<ly;i++)
	{
		int carry=0;
		for(int j=0;j<lx;j++)
		{
			int tt=(b[i+j]+(int(y[ly-i-1])-48)*(int(x[lx-j-1])-48)+carry)/10;
			b[i+j]=(b[i+j]+(int(y[ly-i-1])-48)*(int(x[lx-j-1])-48)+carry)%10;
			carry=tt;
			//cout<<i<<" "<<j<<" "<<b[i+j]<<" "<<y[ly-i-1]*x[lx-j-1]<<" "<<carry<<endl;	
		}
		b[i+lx]+=carry;
	}
	int tg=0;
	for(int i=lx+ly-1;i>=0;i--)
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
	a=bigmultiply(a,b);
	cout<<a;
	return 0;
} 
