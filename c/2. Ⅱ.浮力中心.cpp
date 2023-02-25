#include<iostream>
using namespace std;
int main()
{
	int n,p,total=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>p;
		if(p>=2000)
		{
			p-=200;
		}
		total+=p;
	}
	cout<<(total-((total/1000)*100));
	return 0;
}
