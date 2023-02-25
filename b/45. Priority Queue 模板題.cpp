#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main()
{
	priority_queue<int>x;
	string a;
	int b,c;
	cin>>b;
	for(int i=0;i<b;i++)
	{
		cin>>a;
		if(a=="PUSH")
		{
			cin>>c;
			x.push(c);
		}
		else if(a=="POP")
		{
			cout<<x.top()<<endl;
			x.pop();
		}
	}
	return 0;
}
