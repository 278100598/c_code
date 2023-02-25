#include<bits/stdc++.h>
using namespace std;
int main()
{
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
    double x,y;
	while(cin>>x)
	{
		y=(x-32)*5/9;
		printf("%.3f", y);
		cout<<endl;
	}
	return 0;
}
