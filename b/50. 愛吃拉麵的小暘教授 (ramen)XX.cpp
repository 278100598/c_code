#include<iostream>
#include<map>
using namespace std;
void out(const map<pair<int,int>,int>ee)
{
	map<pair<int,int>,int>e=ee;
	for(map<pair<int,int>,int>::iterator i=e.begin();i!=e.end();i++)
	{
		cout<<i->first.first<<" "<<i->first.second<<" "<<i->second<<endl;
	}
}
void dd(map<pair<int,int>,int>&e,int mn,int mm)
{
	map<pair<int,int>,int>::iterator i=e.begin();
	while(i!=e.end())
	{
		if(i->first.second<=mn||mm<=i->first.first)
		{
			i++;
		}
		else
		{
			//cout<<i->first.first<<" "<<i->first.second<<endl;
			e.erase(i++);
		}
	}
}
int money(map<map<pair<int,int>,int>,int>&x,map<pair<int,int>,int>e,int mn,int mm)
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	//cout<<"in "<<mn<<" "<<mm<<endl;
	dd(e,mn,mm);
	if(e.empty())
	{
		//cout<<mm<<" "<<mn<<" 000"<<endl;
		return 0;
	}
	if(x.find(e)!=x.end())
	{
		return x.find(e)->second;
	}
	else
	{
		//out(e);
		//cout<<endl;
		int m=0;
		for(map<pair<int,int>,int>::iterator i=e.begin();i!=e.end();i++)
		{
			m=max(m,money(x,e,i->first.first,i->first.second)+i->second);
		}
		//cout<<"out "<<mn<<" "<<mm<<" "<<m<<endl<<endl;
		x[e]=m;
		return m;
	}
}
int main()
{
	int n,a,b,c,mm=-1,mn=1000000;
	cin>>n;
	map<pair<int,int>,int>e;
	map<map<pair<int,int>,int>,int>x;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b>>c;
		e[pair<int,int>(a,b)]=c;
	}
	//for(map<pair<int,int>,int>::iterator i=e.begin();i!=e.end();i++)
	{
		//cout<<i->first.first<<" "<<i->first.second<<" "<<i->second<<endl;
	}
	int m=0;
	for(map<pair<int,int>,int>::iterator i=e.begin();i!=e.end();i++)
	{
		m=max(m,money(x,e,i->first.first,i->first.second)+i->second);
	}
	cout<<m<<endl;
	//for(map<map<pair<int,int>,int>,int>::iterator l=x.begin();l!=x.end();l++)
	{
		//out(l->first);
		//cout<<l->second<<endl<<endl;
	}
	return 0;
}
