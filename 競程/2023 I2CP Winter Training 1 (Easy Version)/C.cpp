#include<iostream>
#include<algorithm>
using namespace std;
string s;
int cnt=0;

int main() {
	cin>>s;
	reverse(s.begin(),s.end());
	s.pop_back();
	int cnt=s.size();
	
	bool fs=false;
	for(char c:s) {
		if(c=='1') {
			if(!fs) {
				cnt++;
				fs=true;
			}
		} else {
			if(fs) cnt++;
		}
	}
	
	if(fs) cout<<cnt+1;
	else cout<<cnt;
	
	return 0;
}
