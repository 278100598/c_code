#include<iostream>
using namespace std;
long long int total=0,n,m,k;
bool **cake;
void cut(int xx,int yy)
{
	int stop=m;
	for(int y=yy;y<n;y++)
	{
		for(int x=xx;x<m;x++)
		{
			if(stop==xx)
			{
				y=n;
				break;
			}
			else if(stop==x)
			{
				break;
			}
			if(!cake[x][y])
			{
				if((x-xx+1)*(y-yy+1)<=k)
				{
					total++;
				}
				else
				{
					break;
				}
			}
			else
			{
				stop=x;
				break;
			}
		}
	}
}
int main()
{
	cin>>n>>m>>k;
	cake=new bool*[m];
	bool clean=true;
	for(int i=0;i<m;i++)
	{
		cake[i]=new bool[n];
	}
	for(int y=0;y<n;y++)
	{
		for(int x=0;x<m;x++)
		{
			cin>>cake[x][y];
			if(cake[x][y])
			{
				clean=false;
			}
		}
	}
	if(clean&&k==n*m)
	{
		for(int y=0;y<n;y++)
		{
			for(int x=0;x<m;x++)
			{
				total+=(n-y)*(m-x);
			}
		}
	}
	else
	{
		for(int y=0;y<n;y++)
		{
			for(int x=0;x<m;x++)
			{
				if(!cake[x][y])
				{
					cut(x,y);
				}
			}
		}	
	}
	cout<<total;
	return 0;
}
