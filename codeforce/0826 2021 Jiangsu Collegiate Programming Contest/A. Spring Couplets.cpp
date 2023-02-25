#include<iostream>
using namespace std;
int T,N;
bool level[21];

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>T;
	while(T--) {
		bool y=true;
		cin>>N;
		string s;
		for(int i=0;i<N;i++) {
			cin>>s;
			if(s[s.size()-1] == '1' || s[s.size()-1] == '2') level[i]=true;
			else if(s[s.size()-1] == '3' || s[s.size()-1] == '4') level[i]=false;
		} 
		
		if(level[N-1]) {
			y=false;
		}
		
		for(int i=0;i<N;i++) {
			bool l;
			cin>>s;
			if(s[s.size()-1] == '1' || s[s.size()-1] == '2') l=true;
			else if(s[s.size()-1] == '3' || s[s.size()-1] == '4') l=false;
			if(!(l ^ level[i])) y=false;
		}
		
		if(y) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
	
	return 0;
} 
