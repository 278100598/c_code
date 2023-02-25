#include<iostream>
#include<vector>
using namespace std;
int N,x[1000];

int main() {
	while(cin>>N) {
		if(N==0) break;
		
		while(cin>>x[0]) {
			if(x[0]==0) break;
			for(int i=1;i<N;i++) cin>>x[i];
			
			vector<int> st;
			bool flag=true;
			for(int i=0,top=1;i<N;i++) {
				while(top<x[i]) {
					st.push_back(top++);
				}
				if(top == x[i]) top++;
				else if(!st.empty() && st.back()==x[i]) st.pop_back();
				else {
					flag=false;
					break;
				}
			}
			
			if(flag) cout<<"Yes\n";
			else cout<<"No\n";
		}
		cout<<'\n';
	}
	
	
	return 0;
}
