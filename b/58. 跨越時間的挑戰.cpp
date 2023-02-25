#include<iostream>
#include<map>
#include<set>
using namespace std;
map<string,int>game[560],now;
pair<string,int>win[560],choose[666];
int m=0,day=1,j=0;
string name;
void go(int stop)
{
	string s;
	int x;
	for(int i=0;i<j;i++)
	{
		s=choose[i].first;
		if(s=="end")
		{
			cout<<name<<endl;
		}
		else
		{
			x=choose[i].second;
			now[s]+=x;
			if(now[s]>m)
			{
				m=now[s];
				name=s;
			}
			if(day<stop)
			{
				game[day]=now;
				win[day]=pair<string,int>(name,m);
			}
			day++;
		}
	}
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,x,y;
	cin>>n;
	string s;
	game[0]=now;
	win[0]=pair<string,int>("x",0);
	for(int i=0;i<n;i++,j++)
	{
		cin>>s;
		if(s=="end")
		{
			choose[j]=pair<string,int>("end",0);
		}
		else if(s=="leap")
		{
			cin>>x;
			go(x);
			day=x;
			now=game[x-1];
			name=win[x-1].first;
			m=win[x-1].second;
			j=-1;
		}
		else
		{
			cin>>x;
			choose[j]=pair<string,int>(s,x);
		}
	}
	if(s=="end")
	{
		go(0);
	}
	return 0;
}
