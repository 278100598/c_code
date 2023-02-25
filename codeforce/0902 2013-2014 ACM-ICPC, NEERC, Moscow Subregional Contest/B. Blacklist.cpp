#include<iostream>
using namespace std;

int x[16];
bool vis[16];
string s;

int main() {
	for(int i=0;i<16;i++) x[i]=0;
	cin>>s;
	for(int i=0;i<s.size();i++) {
		int j=s.size()-1-i;
		if('0'<=s[i] && s[i]<='9') x[j]=s[i]-'0';
		else if('A'<=s[i] && s[i]<='F') x[j]=s[i]-'A'+10;
	}
	
	int add=0,high = s.size()-1;
	while(true) {
		x[add]++;
		if(x[add] == 16) {
			x[add]=0;
			add++;
		} else break;
		
		if(high < add) high = add;
	}
	
	while(true) {
		
		add=-1;
		for(int i=0;i<16;i++) vis[i]=false; 
		for(int i=high;i>=0;i--) {
			if(!vis[x[i]]) vis[x[i]]=true;
			else {
				add=i;
				break;
			}
		}
		
		if(add==-1) {
			for(int i=high;i>=0;i--) {
				if(0<=x[i] && x[i]<=9) cout<<char('0'+x[i]);
				else if(10<=x[i] && x[i]<=15) cout<<char('A'+(x[i]-10));
			}
			return 0;
		} else {
			for(int i=0;i<add;i++) x[i]=0;
			while(true) {
				x[add]++;
				if(x[add] == 16) {
					x[add]=0;
					add++;
				} else break;
				
				if(high < add) high =add;
			}
		}
	}
	
	return 0;
}
