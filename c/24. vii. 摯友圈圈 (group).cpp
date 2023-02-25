#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> *x;
int n,m;
int bfs(vector<int>a,int p)
{
	int mm=p;
	for(int i=0;i<n;i++)
	{
		if(find(a.begin(),a.end(),i)==a.end())
		{
			bool y=true;
			for(auto j:a)
			{
				if(find(x[j].begin(),x[j].end(),i)==x[j].end())
				{
					y=false;
					break;
				}
			}
			if(y)
			{
				a.push_back(i);
				mm=max(mm,bfs(a,p+1));
				a.pop_back();
			}
		}
	}
	return mm;
}
int main()
{
	int mm=0;
	cin>>n>>m;
	x=new vector<int>[n];
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		x[a].push_back(b);
		x[b].push_back(a);
	}
	for(int i=0;i<n;i++)
	{
		if(x[i].size())
		{
			vector<int>t;
			t.push_back(i);
			mm=max(mm,bfs(t,1));
		}
	}
	cout<<mm;
	return 0;
}
