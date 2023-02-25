#include<iostream>
#include<map>
using namespace std;
struct ramen
{
	int b;
	int e;
	int m;
};
int money(map<pair<int,int>,int>&x,map<pair<int,int>,int>&e,int mn,int mm)
{
	if(x.find(pair<int,int>(mn,mm))!=x.end())
	{
		return x.find(pair<int,int>(mn,mm))->second;
	}
	else if(mn+1==mm)
	{
		return 0;
	}
	int m=0;
	for(int i=mn+1;i<mm;i++)
	{
		m=max(m,money(x,e,mn,i)+money(x,e,i,mm));
	}
	if(e.find(pair<int,int>(mn,mm))!=e.end())
	{
		m=e.find(pair<int,int>(mn,mm))->second;
		e.erase(pair<int,int>(mn,mm));
	}
	x[pair<int,int>(mn,mm)]=m;
	cout<<mn<<" "<<mm<<" "<<m<<endl;
	return m;
}
int main()
{
	int n,a,b,c,mm=-1,mn=1000000;
	cin>>n;
	map<pair<int,int>,int>x,e;
	ramen mmm,nnn;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b>>c;
		e[pair<int,int>(a,b)]=c;
		mm=max(mm,b);
		mn=min(mn,a);
	}
	//for(map<pair<int,int>,int>::iterator i=e.begin();i!=e.end();i++)
	{
		//cout<<i->first.first<<" "<<i->first.second<<" "<<i->second<<endl;
	}
	cout<<money(x,e,mn,mm);
	return 0;
}
