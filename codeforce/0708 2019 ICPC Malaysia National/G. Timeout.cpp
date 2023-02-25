#include<iostream>
#include<vector>
using namespace std;
struct TK {
	int size=0;
	vector<int> depend;
	bool call,depended=false;
	long long int x,time=-1;
};
struct EP {
	int size=0;
	long long int time=-1;
	TK *tasks;
};
EP *ep;
const int MOD=1000000007;
void go(int a,EP *e);

long long int goo(int a,TK *t,int index) {
	if(t[index].time!=-1) return t[index].time;
	long long int time,mx=0;
	if(t[index].call) {
		go(t[index].x,ep+t[index].x);
		time = ep[t[index].x].time+1;
	} else {
		time = t[index].x;
	}
	for(auto it=t[index].depend.begin();it!=t[index].depend.end();it++) {
		mx = max(mx,goo(a,t,*it));
	}
	t[index].time = (time+mx)%MOD;
	//cout<<"CRT " << a << " " << index << " DPC " << t[index].size << " " << t[index].time <<endl;
	return t[index].time;
}

void go(int a,EP *e) {
	if(e->time!=-1) return;
	long long int mx=0;
	for(int i=1;i<=e->size;i++) {
		//if(e->tasks[i].depended) continue;
		mx = max(goo(a,e->tasks,i),mx);
	}
	e->time = mx;
	//cout<<"CRE " << a << " " << mx<<endl;
}

int main() {
	std::ios_base::sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	ep = new EP[n+1];
	for(int i=1;i<=n;i++) {
		cin>>ep[i].size;
		ep[i].tasks = new TK[ep[i].size+1];
		for(int j=1;j<=ep[i].size;j++) {
			TK *t=&ep[i].tasks[j];
			cin>>t->size;
			for(int k=0;k<t->size;k++) {
				int x;
				cin>>x;
				ep[i].tasks[x].depended=true;
				t->depend.push_back(x);
			}
			cin>>t->call>>t->x;
		}
	}
	
	for(int i=0;i<m;i++) {
		int index;
		cin>>index;
		EP *e=&ep[index];
		go(index,e);
		cout<<e->time<<endl;
	}
	
	return 0;
} 
