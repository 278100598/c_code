#include<iostream>
#include<vector>
using namespace std;
struct Node {
	int color=-1,from=-1;
	vector<int> go;
} node[200001];
vector<int> ans1,ans2;
int N,M,S;

bool dfs(int x,int pre,int col) {
	//cout<<x<<' '<<pre<<' '<<col<<endl;
	if(node[x].from != -1 && node[x].color != col) {
		int it=pre;
		ans1.push_back(x);
		while(it != S) {
			ans1.push_back(it);
			it = node[it].from;
		}
		ans1.push_back(S);
		it = x;
		while(it != S) {
			ans2.push_back(it);
			it = node[it].from;
		}
		ans2.push_back(S);
		
		return true;
	}
	
	node[x].from = pre;
	node[x].color= col;
	
	for(int to:node[x].go) {
		if(to==S || node[to].color==col) continue;
		if(dfs(to,x,col)) return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0);
	cin>>N>>M>>S;
	for(int i=0;i<M;i++) {
		int a,b;
		cin>>a>>b;
		node[a].go.push_back(b);
	}
	
	for(int i:node[S].go) {
		if(dfs(i,S,i)) break;
	}
	
	if(ans1.empty()) {
		cout<<"Impossible";
		return 0;
	}
	
	cout<<"Possible\n";
	cout<<ans1.size()<<'\n';
	for(int i=ans1.size()-1;i>=0;i--) cout<<ans1[i]<<" \n"[(i==0?1:0)];
	cout<<ans2.size()<<'\n';
	for(int i=ans2.size()-1;i>=0;i--) cout<<ans2[i]<<" \n"[(i==0?1:0)];
	return 0;
}
