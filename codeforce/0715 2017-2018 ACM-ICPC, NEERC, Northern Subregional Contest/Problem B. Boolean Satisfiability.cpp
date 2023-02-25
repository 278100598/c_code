#include<iostream>
using namespace std;
int c[300][2];
int main() {
	freopen("boolean.in","r",stdin);    // Åª file.in ÀÉ
	freopen("boolean.out","w",stdout);  // ¼g¤J file.out ÀÉ
	for(int i=0;i<300;i++) {
		c[i][0]=0;
		c[i][1]=0;	
	}
	string s;
	cin>>s;
	for(int i=0;i<s.size();i+=2) {
		bool y=true;
		if(s[i]=='~') {
			y=false;
			i++;
		}
		c[s[i]][(y?1:0)]++;
	}
	long long int sum=1,power=0,count=0;
	for(int i=0;i<300;i++) {
		if(c[i][1]>0&&c[i][0]>0) power++;
		else if(c[i][1]>0||c[i][0]>0) sum*=2;
		if(c[i][1]>0||c[i][0]>0) count++;
	}
	if(s.size()==0) {
		cout<<0;
	} else if(power==0){
		if(sum>1) sum-=1;
		cout<<sum;
	}
	else {
		long long int out=1;
		while(count>0) {
			out*=2;
			count--;
		}
		cout<<out;
	}
	return 0;
} 
