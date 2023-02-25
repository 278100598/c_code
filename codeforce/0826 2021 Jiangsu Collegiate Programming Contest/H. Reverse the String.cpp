#include<iostream>
#include<algorithm>
using namespace std;
int keep[26],T;

int main() {
	cin>>T;
	while(T--) {
		string s;
		cin>>s;
		for(int i=0;i<26;i++) keep[i]=0;
		for(int i=0;i<s.size();i++) keep[s[i]-'a']++;
		
		int head=s.size(),now=0;
		for(int i=0;i<s.size();i++) {
			while(keep[now]==0) now++;
			
			if(now != s[i]-'a') {
				head=i;
				break;
			}
			keep[now]--;
		}
		
		if(head==s.size()) {
			cout<<s<<endl;
			continue;
		}
		
		bool ready=false;
		string t = "", mx = s.substr(head);
		reverse(mx.begin(),mx.end());
		for(int i=head;i<s.size();i++) {
			if(s[i]-'a' != now && ready) {
				if(mx > t+s.substr(i)) mx = t+s.substr(i);
				ready=false;
			}
			if(s[i]-'a' == now) ready=true;
			t = s[i]+t;
		}
		cout<<s.substr(0,head)<<mx<<endl;
	}
	
	return 0;
} 

