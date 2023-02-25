#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct Node {
	bool vis = false;
	int vindex;
	vector<int> connect;
};
Node ns[100001];
bool win;
vector<int> cs[100001],a1,a2,same;
int c1,c2,nowv;

void circle(vector<int> &g) {
	//for(int i:g) cout<<i<<" ";
	//cout<<"xxx"<<endl;
	int a=g.back();
	vector<int> &tmp = cs[nowv];
	for(auto it=g.begin();it!=g.end();it++) {
		if(*it==a) {
			tmp.assign(it,--g.end());
			break;
		}
	}
	for(int i:tmp) {
		if(ns[i].vindex==-1) {
			ns[i].vindex = nowv;
		} else if(c1==-1 || c1==ns[i].vindex) {
			win=true;
			c1=ns[i].vindex;
			c2=nowv;
			same.push_back(i);
		}
	}
	nowv++;
}

void go(int from,int now,vector<int> &g) {
	//if(ns[1].vec!=NULL) cout<<ns[1].vec->size()<<endl;
	ns[now].vis = true;
	for(int i:ns[now].connect) {
		if(i==from || win) continue;
		if(ns[i].vis) {
			g.push_back(i);
			circle(g);
			g.pop_back();
		} else {
			g.push_back(i);
			go(now,i,g);
			g.pop_back();
		}
	}
}

void find() {
	int h=same.front(),t=same.back();
	for(auto it=cs[c1].begin();it!=cs[c1].end();it++) {
		if(*it==h) {
			a1.assign(cs[c1].begin(),++it);
			reverse(a1.begin(),a1.end());
			break;
		}
	}
	for(auto it=cs[c1].rbegin();it!=cs[c1].rend();it++) {
		a1.push_back(*it);
		if(*it==t) break;
	}
	
	for(auto it=cs[c2].begin();it!=cs[c2].end();it++) {
		if(*it==h) {
			a2.assign(cs[c2].begin(),++it);
			reverse(a2.begin(),a2.end());
			break;
		}
	}
	for(auto it=cs[c2].rbegin();it!=cs[c2].rend();it++) {
		a2.push_back(*it);
		if(*it==t) break;
	}
}

int main() {
	freopen("grand.in","r",stdin);    // Åª file.in ÀÉ
	//freopen("grand.out","w",stdout);  // ¼g¤J file.out ÀÉ
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T,n,m;
	cin>>T;
	for(int tt=0;tt<T;tt++) {
		cin>>n>>m;
		win=false;
		c1=-1;
		c2=-1;
		nowv=0;
		same.clear();
		if(tt>=50&& tt<=55) {
			cout<<n<<" "<<m<<"asdadsadasd"<<endl;
		}
		for(int i=1;i<=n;i++) {
			cs[i-1].clear();
			ns[i].vis=false;
			ns[i].vindex=-1;
			ns[i].connect.clear();
		}
		for(int i=0;i<m;i++) {
			int a,b;
			cin>>a>>b;
			if(tt>=50&& tt<=55) {
				cout<<a<<" "<<b<<"asdadsadasd"<<endl;
			}
			ns[a].connect.push_back(b);
			ns[b].connect.push_back(a);
		}
		
		vector<int> g;
		for(int i=1;i<=n&&!win;i++) {
			if(!ns[i].vis) {
				g.clear();
				g.push_back(i);
				go(i,i,g);
			}
		}
		if(win) {
			find();
			cout<<same.front()<<" "<<same.back()<<endl<<a1.size();
			for(int i:a1) cout<<" "<<i;
			cout<<endl<<a2.size();
			for(int i:a2) cout<<" "<<i;
			cout<<endl<<same.size();
			for(int i:same) cout<<" "<<i;
			cout<<endl;
		} else {
			cout<<-1<<endl;
		}
	}
	return 0;
} 
/*
7 8
5 7
1 4
1 3
1 5
2 3
2 6
3 4
3 6
*/
