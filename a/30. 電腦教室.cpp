#include<bits/stdc++.h>
using namespace std;
int main()
{
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
    int a,x,ma;
    cin>>x;
    cin>>a;
    ma=a;
    x--;
	while(x>0)
	{
		cin>>a;
		ma=max(ma,a);
		x--;
	}
	cout<<ma<<endl;
	return 0;
}
