#include<iostream>
#include<vector>
using namespace std;
int N,M;
int table[502][502];
bool vis[502][502];
vector<pair<int,int>> ans,even,odd;

void dfs(int row, int column) {
	int x=table[row][column];
	
	vis[row][column] = true;
	if((row+column)%2==0) even.push_back(make_pair(row,column));
	else odd.push_back(make_pair(row,column));
	
	if(!vis[row+1][column] && x==table[row+1][column]) dfs(row+1,column);
	if(!vis[row-1][column] && x==table[row-1][column]) dfs(row-1,column);
	if(!vis[row][column+1] && x==table[row][column+1]) dfs(row,column+1);
	if(!vis[row][column-1] && x==table[row][column-1]) dfs(row,column-1);
}

int main() {
	cin>>N>>M;
	for(int i=0;i<=N+1;i++) {
		table[i][0]=0;
		table[i][M+1]=0;
	}
	for(int i=1;i<=M;i++) {
		table[0][i]=0;
		table[N+1][i]=0;
	}
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=M;j++) {
			cin>>table[i][j];
			vis[i][j]=false;
		}
	}
	
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=M;j++) {
			if(!vis[i][j]) {
				even.clear();
				odd.clear();
				dfs(i,j);
				if(even.size() > odd.size()) {
					ans.insert(ans.end(),odd.begin(),odd.end());
				} else {
					ans.insert(ans.end(),even.begin(),even.end());
				}
			}
		}
	}
	
	if(ans.size()==0) {
		cout<<"0 0";
		return 0;
	}
	cout<<"1 "<<ans.size()<<endl;
	for(auto i:ans) {
		cout<<i.first<<" "<<i.second<<" "<<1<<endl;
	}
	return 0;
} 
