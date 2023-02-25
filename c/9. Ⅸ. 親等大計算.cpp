#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main()
{
	int n,l,r;
	cin>>n;
	int step[n];
	bool v[n]{};
	vector<int>*f=new vector<int>[n];
	queue<int>q;
	for(int i=1;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		f[a].push_back(b);
		f[b].push_back(a);
	}
	cin>>l>>r;
	q.push(r);
	step[r]=0;
	while(!q.empty()&&!v[l])
	{
		for(int i=0;i<f[q.front()].size();i++)
		{
			if(!v[f[q.front()][i]])
			{
				step[f[q.front()][i]]=step[q.front()]+1;
				v[f[q.front()][i]]=true;
				q.push(f[q.front()][i]);
			}
		}
		q.pop();
	}
	cout<<step[l];
	return 0;
}
