#include<iostream>
using namespace std;
string s;
int main() {
	cin>>s;
	char c=' ';
	int cnt=1,mx=0;
	for(int i=0;i<s.size();i++) {
		if(c==s[i]) cnt++;
		else {
			cnt=1;
			c=s[i];
		}
		mx = max(cnt,mx);
	}
	cout<<mx;
	
	return 0;
}
