#include<iostream>
#include<set>
using namespace std;
int N;
bool have[26];
set<string> st;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>N;
	for(int i=0;i<N;i++) {
		string s;
		cin>>s;
		have[s[0]-'A']=true;
		st.insert(s);
	}
	
	for(string s:st) {
		bool y=true;
		
		for(int i=0;i<s.size();i++) {
			if(!have[s[i]-'A']) {
				y=false;
				break;
			}
		}
		if(y) {
			cout<<"Y";
			return 0;
		}
	}
	cout<<"N";
	return 0;
} 
