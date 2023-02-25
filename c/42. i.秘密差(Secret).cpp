#include<iostream>
#include<string>
using namespace std;
int main() {
	string s;
	cin>>s;
	bool y=true;
	int sum=0;
	for(int i=0;i<s.size();i++) {
		if(y) {
			sum+=s[i]-'0';
		} else {
			sum-=s[i]-'0';
		}
		y = !y;
	}
	cout<<(sum>0?sum:-1*sum);
	
	return 0;
} 
