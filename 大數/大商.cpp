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
	int tg;
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
string bigdivide(string x,string y)
{
	if(y.size()>x.size()||(y>x&&y.size()==x.size()))
	{
		return "0";
	}
	int lx=x.size(),ly=y.size();
	string q="0",r,ten="1";
	for(int i=ly;i<lx;i++)
	{
		ten+="0";
	}
	while(true)
	{
		//cout<<x<<" "<<x.size()<<" "<<bigmultiply(y,ten).size()<<" "<<bigmultiply(y,ten)<<endl;
		if(x.size()<bigmultiply(y,ten).size()||(bigmultiply(y,ten)>x&&bigmultiply(y,ten).size()==x.size()))
		{
			ten=ten.substr(0,(x.size()<ly?0:x.size()-ly+1));
			if((bigmultiply(y,ten)>x&&bigmultiply(y,ten).size()==x.size()))
			{
				ten=ten.erase(ten.size()-1);
			}
		}
		if(x=="0")
		{
			break;
		}
		else if(x.size()<y.size()||(y>x&&y.size()==x.size()))
		{
			break;
		}		
		x=bigsubtract(x,bigmultiply(y,ten));
		q=bigadd(q,ten);
	}
	r=x;
	return q;
}
int main()
{
	string a,b;
	cin>>a>>b;
	a=bigdivide(a,b);
	cout<<a;
	return 0;
}
