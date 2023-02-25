#include<iostream>
using namespace std;
int main() {
	freopen("auxiliary.in","r",stdin);    // Åª file.in ÀÉ
	freopen("auxiliary.out","w",stdout);  // ¼g¤J file.out ÀÉ
	int n,out=0;
	cin>>n;
	out+=((n/3)*7);
	if(n%3==2)out+=1;
	if(n%3==1)out-=3;
	cout<<out;
	return 0;
}
