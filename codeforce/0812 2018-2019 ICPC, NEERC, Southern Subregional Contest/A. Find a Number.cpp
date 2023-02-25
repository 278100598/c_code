#include<iostream>
#include<queue>
using namespace std;

struct Str{
	int mod,cnt;
	string s;
	Str(int m,int n,string str) {
		mod=m;
		cnt=n;
		s=str;
	} 
};

int D,S;
queue<Str> q;
bool visit[501][5001];

int main() {
	cin>>D>>S;
	
	for(int i=0;i<=D;i++) {
		for(int j=0;j<=S;j++) {
			visit[i][j]=false;
		}
	}
	
	q.push(Str(0,0,""));
	while(!q.empty()) {
		Str &x = q.front();
		//cout<<x.s<<endl;
		if(x.mod==0 && x.cnt==S) {
			cout<<x.s;
			return 0;
		}

		for(int i=0;i<=9;i++) {
			int cnt = x.cnt+i, mod = (x.mod*10+i)%D;
			//cout<<mod<<" "<<cnt<<endl;
			if(cnt <= S && !visit[mod][cnt]) {
				q.push(Str(mod,cnt,x.s+char('0'+i)));
				visit[mod][cnt]=true;
			}
		}
		q.pop();
	}
	cout<<-1;
	
	return 0;
}
