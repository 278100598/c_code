#include<bits/stdc++.h>
using namespace std;
int main()
{
	stack<int>x;
	string s;
	int a,b,c;
	cin>>a>>b;
	for(int i=0;i<b;i++)
	{
		int y=0;
		bool yn=true;
		for(int j=0;j<a;j++)
		{
			cin>>c;
			while(x.empty()||x.top()!=c)
			{
				if(y>a)
				{
					yn=false;
					break;
				}
				x.push(y);
				y++;
			}
			if(x.top()==c)
			{
				x.pop();
			}
		}
		if(yn)
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			cout<<"No"<<endl;
		}
	}
	return 0;
}
