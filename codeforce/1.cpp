#include<iostream>
using namespace std;
long long int MX=1e9;
int main() {
	string s;
	cin>>s;
	long long int x=0;
	for(int i=0;i<MX;i++) x+=i;
	s += to_string(x);
	cout<<"Welcome to Ocean Cup, "+s;
	return 0;
} 
