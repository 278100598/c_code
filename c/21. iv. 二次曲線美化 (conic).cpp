#include<iostream>
using namespace std;
int main()
{
	bool f=true;
	string s[5]={"x^2","xy","y^2","x","y"};
	int x[6];
	for(int i=0;i<6;i++)cin>>x[i];
	for(int i=0;i<5;i++)
	{
		if(x[i]!=0)
		{
			if(f)
			{
				if(x[i]<0)cout<<'-';
				f=false;
			}
			else if(x[i]<0)cout<<" - ";
			else cout<<" + ";
			if(x[i]!=1&&x[i]!=-1)cout<<((x[i]<0)?x[i]*-1:x[i]);
			cout<<s[i];
		}
	}
	if(x[5]!=0)
	{
		if(f)
		{
			if(x[5]<0)cout<<'-';
			f=false;
		}
		else if(x[5]<0)cout<<" - ";
		else cout<<" + ";
		cout<<((x[5]<0)?x[5]*-1:x[5]);
	}
	if(f)cout<<0;
	return 0;
}
