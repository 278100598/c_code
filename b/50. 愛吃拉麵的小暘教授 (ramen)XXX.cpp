#include<iostream>
#include<map>
using namespace std;
void dd(map<pair<int,int>,int>&x,int mn,int mm)
{
	for(map<pair<int,int>,int>::iterator i=x.begin();i!=x.end();)
	{
		if(mn<=i->first.first&&i->first.second<=mm)
		{
			i++;
		}
		else
		{
			x.erase(i++);
		}
	}
}
long long int money(map<pair<int,int>,long long int>&e,map<pair<int,int>,int>x,int mn,int mm)
{
	//cout<<"in "<<mn<<" "<<mm<<endl;
	if(mn==mm)
	{
		return 0;
	}
	else if(e[pair<int,int>(mn,mm)])
	{
		//cout<<"ok "<<mn<<" "<<mm<<" "<<e.find(pair<int,int>(mn,mm))->second<<endl;
		return e[pair<int,int>(mn,mm)];
	}
	else
	{
		dd(x,mn,mm);
		long long int m=0,c;
		int a,b;
		for(map<pair<int,int>,int>::iterator i=x.begin();i!=x.end();)
		{
			a=i->first.first;
			b=i->first.second;
			c=i->second;
			if(mn<=a&&b<=mm)
			{
				x.erase(i++);
				m=max(m,money(e,x,mn,a)+c+money(e,x,b,mm));
			}
			else
			{
				x.erase(i++);
			}
		}
		//cout<<"out "<<mn<<" "<<mm<<" "<<m<<endl;
		if(e[pair<int,int>(mn,mm)])
		{
			e[pair<int,int>(mn,mm)]=max(m,e[pair<int,int>(mn,mm)]);
		}
		else
		{
			e[pair<int,int>(mn,mm)]=m;
		}
		x.erase(x.begin(),x.end());
		return m;
	}
}
int main()
{
	ios::sync_with_stdio(0);
 	cin.tie(0);
	map<pair<int,int>,long long int>e;
	int n,a,b,c,mn=600000,mm=-1;
	cin>>n;
	map<pair<int,int>,int>x;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b>>c;
		if(x[pair<int,int>(a,b)])
		{
			x[pair<int,int>(a,b)]=c;
		}
		else
		{
			x[pair<int,int>(a,b)]=max(x[pair<int,int>(a,b)],c);
		}
		mn=min(mn,a);
		mm=max(mm,b);
	}
	cout<<money(e,x,mn,mm)<<endl;
	//for(map<pair<int,int>,long long int>::iterator i=e.begin();i!=e.end();i++)
	{
		//cout<<i->first.first<<" "<<i->first.second<<" "<<i->second<<endl;
	}
	return 0;
}
