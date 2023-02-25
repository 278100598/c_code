#include<iostream>
#include<algorithm>
using namespace std;
int e[1000][1001],n,t;
bool yes[1000][1001];
pair<int,int>x[1000];
int bag(int index,int y)
{
	//cout<<"in "<<index<<" "<<y<<endl;
	if(yes[index][y])
	{
		//cout<<"ok "<<index<<" "<<y<<" "<<e[index][y]<<endl;
		return e[index][y];
	}
	int p=x[index].first,w=x[index].second;
	if(p>y)
	{
		if(index==0)
		{
			e[index][y]=0;
		}
		else
		{
			e[index][y]=bag(index-1,y);
		}
	}
	else if(index==0)
	{
		e[index][y]=x[0].second;
	}
	else
	{
		e[index][y]=max(w+bag(index-1,y-p),bag(index-1,y));
	}
	yes[index][y]=true;
	//cout<<"out "<<index<<" "<<y<<" "<<e[index][y]<<endl;
	return e[index][y];
}
int main()
{
	int w,p;
	cin>>n>>t;
	for(int i=0;i<t;i++)
	{
		cin>>p>>w;
		if(p>n)
		{
			t--;
			i--;
			continue;
		}
		else
		{
			x[i]=pair<int,int>(p,w);
		}
	}
	sort(x,x+t);
	if(t!=0)
	{
		cout<<bag(t-1,n)<<endl;
	}
	else
	{
		cout<<0<<endl;
	}
	return 0;
} 
