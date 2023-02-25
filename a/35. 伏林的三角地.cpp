#include<bits/stdc++.h>
using namespace std;
int main()
{
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
    int a,b,c;
    long long int s;
	while(cin>>a>>b>>c)
	{
		s=(a+b+c)/2;
		cout<<s*(s-a)*(s-b)*(s-c)<<endl;
	}
	return 0;
}
