#include<iostream>
#include<map>
using namespace std;
int N;
map<string,int>m;
int main() {
	cin>>N;
	for(int i=0;i<N;i++) {
		string s;
		cin>>s;
		m[s]++;
	}
	string ans="NONE";
	for(auto i:m) {
		if(i.second*2>N) {
			ans=i.first;
			break;
		}
	}
	cout<<ans;
	return 0;
}
