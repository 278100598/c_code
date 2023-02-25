#include<bits/stdc++.h>
using namespace std;
int main()
{
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
    int x,y=0;
	while(cin>>x)
	{
		y=x+35;
		y=y%60; 
		cout<<(60-y)*(y!=0)<<endl;
	}
	return 0;
}
