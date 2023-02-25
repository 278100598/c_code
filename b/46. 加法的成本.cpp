#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main()
{
	priority_queue<long long int,vector<long long int>,greater<long long int> >x;
	int b,c;
	cin>>b;
	for(int i=0;i<b;i++)
	{
		cin>>c;
		x.push(c);
	}
	long long int y=0;
	while(x.size()!=1)
	{
		long long int i=x.top();
		x.pop();
		long long int j=x.top();
		x.pop();
		i+=j;
		y+=i;
		x.push(i);
	}
	cout<<y;
	return 0;
}
