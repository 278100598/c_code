#include<iostream>
#include<algorithm>
using namespace std;
pair<string,int>*x;
int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	int n,a;
	cin>>n;
	x=new pair<string,int>[n];
	string s="";
	for(int i=0;i<n;s="",i++)
	{
		cin>>a;
		for(int j=1;j<24;j++)
		{
			if(a%j<10)
			{
				s+='0';
				s+=char(a%j+48);
			}
			else if(a%j<20)
			{
				s+='1';
				s+=char((a%j)+38);
			}
			else
			{
				s+='2';
				s+=char((a%j)+28);
			}
		}
		x[i]=pair<string,int>(s,a);
	}
	sort(x,x+n);
	for(int i=0;i<n;i++)
	{
		cout<<x[i].second<<" ";
	}
	return 0;
}
