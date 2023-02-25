#include<iostream>
using namespace std;
int kill(int n,int k)
{
	int re,answer=0;
	for(int i=1;i<=n;i++)
	{
		re=answer;
		answer=(answer+k)%(i);
	}
	return answer;
}
int main()
{
	int n,k,m;
	while(cin>>n>>k>>m)
	{
		if(n==0&&k==0&&m==0)
		{
			break;
		}
		cout<<(m+kill(n-1,k))%n+1<<endl;
	}
	return 0;
}
