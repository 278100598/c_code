#include<iostream>
#include<unordered_set>
using namespace std;
int N,M;
unordered_set<int> st;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	while(cin>>N>>M) {
		if(N==0&&M==0) break;
		st.clear();
		for(int i=0;i<N;i++) {
			int x;
			cin>>x;
			st.insert(x);
		}
		
		int cnt=0;
		for(int i=0;i<M;i++) {
			int x;
			cin>>x;
			if(st.count(x)) cnt++;
		}
		
		cout<<cnt<<'\n';
	}
	return 0;
}
