#include<iostream>
#include<stack>
using namespace std;
int main() {
	int n,x;
	stack<int>st;
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>x;
		st.push(x);
	}
	cout<<st.top();
	st.pop();
	while(!st.empty()) {
		cout<<" "<<st.top();
		st.pop();
	}
	return 0;
} 
