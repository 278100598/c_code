#include<bits/stdc++.h>
using namespace std;
int main()
{
	queue<int>x;
	string a;
	int y,b;
	cin>>b; 
	for(int i=0;i<b;i++)
	{
		cin>>a;
		if(a=="PUSH")
		{
			cin>>y;
			x.push(y);
		}
		else if(a=="POP")
		{
			cout<<x.front()<<endl;
			x.pop();
		}
	}
	return 0;
}
