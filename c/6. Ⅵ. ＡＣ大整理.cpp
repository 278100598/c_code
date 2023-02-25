#include<iostream>
#include<set>
using namespace std;
int main()
{
	set<pair<int,int> >s;
	int x;
	while(cin>>x&&x!=EOF)
	{
		int n=0,xx=x;
		while(xx>0)
		{
			n+=xx%10;
			xx/=10;
			if(xx==0&&n>=10)
			{
				xx=n;
				n=0;
			}
		}
		s.insert(pair<int,int>(n,x));
	}
	for(pair<int,int> i:s)
	{
		cout<<i.second<<endl;
	}
	return 0;
}
