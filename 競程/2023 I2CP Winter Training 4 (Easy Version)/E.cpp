#include<iostream>
#include<algorithm>
using namespace std;
string s;
int A,B;

int getv(char c) {
	if('0' <= c && c <='9') return c-'0';
	else return c-'A'+10;
}

char getc(int x) {
	if(0<=x && x<=9) return '0'+x;
	else return 'A'+(x-10);
}

int main() {
	while(cin>>s>>A>>B) {
		long long int sum=0;
		for(int i=0;i<s.size();i++) {
			sum*=A;
			sum += getv(s[i]);
		}
		
		string ans="";
		if(sum==0) ans="0";
		while(sum != 0) {
			ans+=getc(sum%B);
			sum/=B;
		}
		
		reverse(ans.begin(),ans.end());
		if(ans.size()>7) cout<<"  ERROR\n";
		else cout<<string(7-ans.size(),' ')<<ans<<'\n';
	}
	
	return 0;
}
