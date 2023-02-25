#include<iostream>
#include<deque>
using namespace std;

int N,M,board[101];
pair<int,int> hero[101];
deque<int> ld,rd;

int main() {
	cin>>N>>M;
	for(int i=0;i<=N;i++) hero[i]=make_pair(-1,-1);
	for(int i=1;i<=M;i++) {
		int p,h;
		cin>>p>>h;
		hero[p]=make_pair(h,i);
	}
	for(int i=1;i<=N;i++) {
		cin>>board[i];
	}
	
	int l=-1,r=N+1,mxhp=-1;
	for(int i=1;i<=N;i++) {
		if(board[i] == 0 && hero[i].first != -1) {
			if(mxhp < hero[i].first ) ld.push_front(hero[i].second);
			else ld.push_back(hero[i].second);
			mxhp = max(mxhp,hero[i].first);
		}
		if(mxhp == -1) continue;
		
		if(board[i] != 0) {
			mxhp+=board[i];
			if(mxhp < 0) {
				break;
			}
		}
		l=i;
	}
	mxhp=-1;
	for(int i=N;i>=0;i--) {
		if(board[i] == 0 && hero[i].first != -1) {
			if(mxhp < hero[i].first ) rd.push_front(hero[i].second);
			else rd.push_back(hero[i].second);
			mxhp = max(mxhp,hero[i].first);
		}
		if(mxhp == -1) continue;
		
		if(board[i] != 0) {
			mxhp+=board[i];
			if(mxhp < 0) {
				break;
			}
		}
		r=i;
	}
	
	if(r <= l+1) {
		cout<<l<<endl;
		bool vis[101];
		for(int i=0;i<=M;i++) vis[i]=false;
		for(int i:ld) {
			vis[i]=true;
			cout<<i<<" ";
		}
		for(int i:rd) {
			if(!vis[i]) cout<<i<<" ";
		}
	} else {
		cout<<-1;
	}
	return 0;
} 
