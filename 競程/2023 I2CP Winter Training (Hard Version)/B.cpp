#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

vector<set<int>> stack;
map<set<int>,int> memo;
int T,N;

int main() {
	
	cin>>T;
	while(T--) {
		stack.clear();
		memo.clear();
		memo[set<int>()]=0;
		cin>>N;
		string o;
		while(N--) {
			cin>>o;
			if(o == "PUSH") {
				stack.push_back(set<int>());
			} else if(o == "DUP") {
				stack.push_back(stack.back());
			} else if(o == "UNION") {
				set<int> &a=stack[stack.size()-1],&b=stack[stack.size()-2];
				set_union(a.begin(),a.end(),b.begin(),b.end(),inserter(b,b.begin()));
				if(memo.find(b) == memo.end()) memo[b]=memo.size();
				stack.pop_back();
			} else if(o == "INTERSECT") {
				set<int> &a=stack[stack.size()-1],&b=stack[stack.size()-2],c;
				set_intersection(a.begin(),a.end(),b.begin(),b.end(),inserter(c,c.begin()));
				stack.pop_back();
				stack.pop_back();
				stack.push_back(c);
				if(memo.find(c) == memo.end()) memo[c]=memo.size();
			} else if(o == "ADD") {
				set<int> &a=stack[stack.size()-1],&b=stack[stack.size()-2];
				if(memo.find(a) == memo.end()) memo[a]=memo.size();
				b.insert(memo[a]);
				stack.pop_back();
			}
			cout<<stack.back().size()<<'\n';
		}
		cout<<"***\n";
	}
	
	return 0;
}
