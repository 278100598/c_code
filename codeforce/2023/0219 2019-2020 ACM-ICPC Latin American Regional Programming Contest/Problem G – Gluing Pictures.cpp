#include<bits/stdc++.h>
using namespace std;
struct Node {
	int road[26];
}nodes[10000000];

string C;
int N,idx=26;
vector<int> now,tmp;
bool vis[26]

int main() {
	cin>>C>>N;
	
	for(int i=0;i<C.size();i++) {
		vis[C[i]-'A']=true;
		now.push_back(C[i]-'A');
		
		tmp.clear();
		
		for(int j:now) {
			if(nodes[j][C[i]-'A']==0) nodes[j][C[i]-'A']=idx;
			else t.push_back(nodes[j][C[i]-'A']);
		}
		idx++;
	}
	
	return 0;
}
