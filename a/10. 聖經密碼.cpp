#include<bits/stdc++.h>
using namespace std;
int main()
{
	cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int x,y;
	while(cin>>x>>y)
	{
		if(x==0&&y==0)
		{
			break;
		}
		string a,b;
		cin.get();
		int z;
		for(int i=0;i<x;i++)
		{
			getline(cin,b);
			a+=b;
		}
		for(int i=0;i<y;i++)
		{
			cin>>z;
			cout<<a[z-1];
		}
		cout<<endl;
	}
	return 0;
}
