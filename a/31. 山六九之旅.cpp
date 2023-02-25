#include<bits/stdc++.h>
using namespace std;
int main()
{
	//cin.tie(NULL);
    //ios_base::sync_with_stdio(false);
    int a;
	while(cin>>a)
	{
		cout<<(6<=a&&a<=11)*590+(12<=a&&a<=17)*790+(18<=a&&a<=59)*890+(60<=a)*399<<endl;
	}
	return 0;
}
