#include<iostream>
using namespace std;
bool vis[26];
string s,tar;
int N;

int main() {
	cin>>N;
	for(int i=0;i<N;i++) {
		cin>>s>>tar;
		int k=tar.size()-1;
		for(int i=0;i<26;i++) vis[i] = false;
		
		for(int j=s.size()-1;j>=0 && k>=0;j--) {
			if(s[j] == tar[k]) {
				if(!vis[tar[k]-'A']) k--;
				else k = -2;
			} else {
				vis[s[j]-'A'] = true;
			}
		}
		
		if(k == -2) cout<<"No\n";
		else if(k == -1) cout<<"Yes\n";
		else cout<<"No\n";
	}
	
	return 0;
}
