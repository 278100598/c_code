#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
int d,**c;
string s;
map<char,int>l;
int cc(int x,int y)
{
	if(y==0||x==y)
	{
		return 1;
	}
	if(y==1)
	{
		return x%d;
	}
	if(c[x][y])
	{
		return c[x][y];
	}
	c[x][y]=(cc(x-1,y)+cc(x-1,y-1))%d;
	//cout<<x<<" "<<y<<" "<<c[x][y]<<endl;
	return c[x][y];
}
int main()
{
	int answer=0;
	cin>>d>>s;
	c=new int*[s.size()+1];
	for(int i=0;i<s.size()+1;i++)c[i]=new int[s.size()+1]{};
	for(auto i:s)
	{
		l[i]++;
	}
	for(int i=0;i<s.size()-1;i++)
	{
		for(auto j=l.begin();j->first!=s[i];j++)
		{
            j->second--;
            long long int len=s.size()-i-1,t=1;
			for(auto &k:l)
			{
				t*=cc(len,k.second);
				t%=d;
				len-=k.second;
			}
			answer+=t;
			answer%=d;
			j->second++;
		}
		l[s[i]]--;
		if(l[s[i]]==0)
		{
			l.erase(s[i]);
		}
		//cout<<answer<<endl;
	}
	cout<<answer;
	return 0;
}
