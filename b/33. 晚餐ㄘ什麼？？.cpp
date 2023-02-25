#include<bits/stdc++.h>
using namespace std;
int main()
{
	set<string>a,b,c;
	int n,m;
	string x;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		a.insert(x);
	}
	for(int i=0;i<m;i++)
	{
		cin>>x;
		b.insert(x);
	}
	set_intersection(a.begin(),a.end(),b.begin(),b.end(),inserter(c,c.end()));
	cout<<c.size()<<endl;
	for(set<string>::iterator i=c.begin();i!=c.end();i++)
	{
		cout<<*i<<endl;
	}
	return 0; 
} 
